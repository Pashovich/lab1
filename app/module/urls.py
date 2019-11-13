from django.urls import path, re_path
from . import views
from django.conf import settings
from django.conf.urls.static import static

urlpatterns = []

urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)

urlpatterns += [
    path('upload/', views.upload, name='upload'),
    re_path(r'^.*download-(?P<name>\S+)', views.download),
    re_path(r'^.*create-(?P<name>\S+)', views.remkdir),
    re_path(r'^.*delete-(?P<name>\S+)', views.delete),
    re_path(r'^', views.indexDir, name='indexDir')
]
