FROM python:3.10

ADD flaskApp.py .

RUN pip install flask

CMD ["python", "./flaskApp.py"]