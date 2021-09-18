# lab1
Функционал работы с директориями и файлами посредствам передачи url
1. Активировать виртуальную среду:
    source venv/bin/activate
2. Запустить сервер из директории app:
    python manage.py runserver


Примеры

1. В изначальной директории будет показана структуру проекта. В строке можно перейти в любую директорию(кроме downloads/)
	* http://127.0.0.1:8000/module 
	* http://127.0.0.1:8000/temp/temp1

2. Создание папки производится командой create-имяпапки
	* http://127.0.0.1:8000/create-tempFolder
	* http://127.0.0.1:8000/temp/create-temp2

3. Удаление пустой папки или файла командой delete-имя и подтвердить метод DELETE
	* http://127.0.0.1:8000/temp/delete-temp1
	* http://127.0.0.1:8000/temp/

4. Скачивание файла производится командой download-имя файла
	* http://127.0.0.1:8000/download-text.txt
	* http://127.0.0.1:8000/module/download-apps.py

5. Форма для загрузки файла на сервер
 	* http://127.0.0.1:8000/upload/
 - Файл будет загружен в директорию downloads/

https://rave.dj/o-0KxSjNEmSFbw
https://rave.dj/nDoX3bStUfRRWQ
https://rave.dj/5L01KwoSf5iq7g
