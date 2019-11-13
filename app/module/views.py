from django.http import HttpResponse, Http404
from rest_framework.decorators import api_view
from rest_framework.response import Response
from django.core.files.storage import FileSystemStorage
import os
import sys
import re

from django.shortcuts import render


sys.path.append('..')
from app import settings


def upload(request):
    if request.method == 'POST':
        uploadedFile = request.FILES['document']
        fileStorage = FileSystemStorage()
        fileStorage.save(uploadedFile.name, uploadedFile)
    return render(request, 'upload.html')

@api_view(['GET'])
def remkdir(request, name):
    path = re.sub(r'/create-\S+', '', request.path)
    print(path)
    dirName = os.path.join(settings.BASE_DIR, os.path.join(clear(path),name))
    if not os.path.exists(dirName):
        os.mkdir(dirName)
        response = "Directory " + str(dirName) + " Created "
    else:
        response = "Directory " + str(dirName) + " already exists"
    return Response({"response": response})


@api_view(['GET'])
def indexDir(request):
    if request.method == 'GET':
        path = clear(request.path)
        path = os.path.join(settings.BASE_DIR, path)
        if os.path.exists(path):
            if os.path.isdir(path):
                response = os.listdir(path)
            else:
                response =str(path) + " is not a directory "
            Response({"Directories": response})
        else:
            response = "Directory" + str(path) + " does not exists "
    return Response(response)


def clear(tempString):
    clearedString = re.sub(r'\A/', '', tempString)
    clearedString = re.sub(r'/$', '', clearedString)
    return clearedString

@api_view(['DELETE'])
def delete(request, name):
    path = re.sub(r'/delete-\S+', '', request.path)
    dirName = os.path.join(settings.BASE_DIR, os.path.join(clear(path), name))
    print(dirName)
    if os.path.exists(dirName):
        if os.path.isdir(dirName):
            if not os.listdir(dirName):
                os.rmdir(dirName)
                response = "Directory " + str(name) + " has been deleted "
            else:
                response = "Directory " + str(name) + " is not empty "
        else:
            os.remove(dirName)
            response ="File " + str(name) +" has been deleted "
    else:
        response =  "Path to file : "+ str(name)+  " \nDoes not exists "
    return Response({"response": response})


@api_view(['GET'])
def download(request, name):
    path = re.sub(r'/download-\S+', '', request.path)
    dirName = os.path.join(settings.BASE_DIR, os.path.join(clear(path), name))
    if os.path.exists(dirName):
        with open(dirName, 'rb') as fh:
            response = HttpResponse(fh.read(), content_type="application/vnd.ms-excel")
            response['Content-Disposition'] = 'inline; filename=' + os.path.basename(dirName)
            return response
    raise Http404
