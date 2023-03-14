# Basic Setup

## Install Python

`python3 --version`

> cmd+ shift + v to view markdown

## Django project setup

- `pip3 install virtual env`
- `virtualenv envname`
  > will create a envname folder
  > activate the env
- `source bin/activate`
- `pip freeze` to know all the packages downloaded

  > then install django in that env.

- `deactivate`

  > to deactivate the virtual env.

  > in virtual env python will be puthon 3 and pip will be pip3

- `pip install django==4.0`

  > will install django in your venv

- `django-admin startproject projectname` or `django-admin startproject projectname .`
  > will create a django project
- `pip install -r requirements.txt`
  > will install all the packages required

# Django Project

## About manage.py

> It is the file which allows to interact with the django project

## **init**.py

> _need to know_

## asgi.py

> Used to to configure app to upload on server

## settings.py

> conatins all the settings for the projects

## urls.py

> All the url patterns for the incoming url request

## wsgi.py

> _need to know !!_`

## Run the project on local server

> django by default will come with server which can used to run the app

> `python manage.py runserver` to start the server

## Difference b/w app and project.

> Apps are nothing but components in react app
> Or we can say that an App is a building block of the project

**Create a App**

> `python manage.py startapp myapp`

# Significance of app dir and files

## views.py

> In views.py we can accept a incoming request and depending on the request we can give back an appropriate response.
> Views is nothing but a function which can accept a req and give back a http response (Logic).

> Create a view in your app and go to urls.py in project/ and import views from your app
> Note : to map a view to / use ""

> **_BEST PRACTICES_**, All the views of an app should be mapped in side the app by creating a urls.py in the app and this urls.py should be **inlcuded** inside the urls.py of the project.

# MODELS & MIGRATIONS

> What ORM does is, once you create a model in models.py django will create a table what that columns in the database

> In django a model is created as class, what differ a python class with a django model is you have inherit a django class models.Model

> **_IMPORTANT_** Transforming a django database model into a database table is called migration
> migration is done on the project, not the app, so the project need to know about the installed apps
> When creating migrations , djnago will create db tables for all the installed apps

> Making migrations is a two step process

> `python manage.py makemigrations` - genrerates migrations files
> `python manage.py migrate` - applies those migrations and sync database with latest migrations

# ORM

## How to insert data inside db using django ORM

> Running python REPl having access django models

> `python manage.py shell`

> `from app.models import ModelClassName`

> `ModelClassName.objects.all()`
> Will give all the objects in that model

## Adding data django model

> `a=ModelClassName(name="iphone", price=999,desc="This is iPhone 14")` will create a object of ModelClassname instance
> when you have created an object you have just created an object , to add that data to table you need to save the object

> `a.save()`

## Reteieving data from django model

> `p1=Product.objects.get(id=1)`

> `p1.name p1.desc p1.price`

## Admin Panel

> **CREATE SUPER USER** `python manage.py createsuperuser`

> **REGISTER MODELS TO ADMIN PANEL** In the app go to admin.py, import the model `from .models import ModelName` and register the model to the admin panel `admin.site.register(ModelName)`

# Templates

> import Model from models and return a `HTTPResponse(Model.objects.all())`

## How to create a template

> Default template engine in django is **ZINGZAW**

> As Django is opinionated we nneed to follow a certain way to create a template to work

> **_IMPORTANT_** Go to app, create a folder templates create a folder with appName and then in that folder create a file with index.html

> In template syntax to access a variable use **SYNTAX** `{{}}`
> To send a html page to the browser upon a req

- Instead on sending a HttpResponse, you need to add the required view inside of render methor and return that render method
- Render method take two args `( request, templatepath,context)`
- A template consists of both static and dynamic path
- To pass the dynamic data you need to pass that dynamic data as context, and **context will be dict (ALWAYS)**
- context={products:products}

## How to loop over a queryset

> for loop will work

> `{% for product in products %}`

- will have access to each product
- here we can write all the html we want

> `{% endfor%}`

## Create a Dynamic route

> To create a dynamic route you need to specify that dynamic value datatype while declaring the route and this will be important further by the way you access the data w.r.t to the dynamic value

> Now that dynamic value will be accessible in the view declared with the sanme variable name and the data type of the variable name will be of the declared one in urls.

## How to not keep hardcoded URL

> we can name urls
> we can do that while declaring the route itself
> after proving the view you can write the name for tyhe url
> `path(/products/<int:id?,views.xyz,name="product_details")`

> ` <a href="{% url 'detail_view' item.id%}"> {{item.id}} {{item.name}} </a>`
> lec 37 HArdocded URLS

## Namespacing URLS

> Required (Best practices) can create a differnce between differnt url name of different apps
> in view create `app_name='appName'`

> ` <a href="{% url 'appName:detail_view' item.id%}"> {{item.id}} {{item.name}} </a>`
> lec:38

## Adding css and tailwind to templates

> Create static folder in your app create another folder with your appname and place all your css files here.
> when you are using static file u nedd to **RESTART THE SERVER**
> for every change in static file u need to **RESTART THE SERVER** to see the changes

- @ the top of the page `{% load static % }`
- Link your css `{ % static 'firstApp/styles.css' %}`

### Installing tailwind for django project

1. Install node
2. Initialize package.json file `npm init -y`
3. Add tailwind `npm i tailwindcss@2.2.16`
4. Create a source folder in static folder and create a tw.css file

# Forms

## Add Data to db

> By default all forms without a method will do GET req, and using GET request to send data to the server is dangerous as it leaks all the data which is being sent tot the server so insted use POST req and by default a function in views thinks of responding to a GET req so which writing a view you need to make the func run only if method is POST

    {% csrf_token%}

> **Cross Site Request Forgery,CSRF token** to fix this error you need to add this`{% csrf_token%}` in the form html code

> In Input

- name = field which we accept
- id=fields which we want to accept

## Update data DB

> create a instance of the Model and find the one which you want to update and change the value of the variable of the class and then save the instance of the model `save()`

`if request.method=="POST": product.name=request.POST.get('name') product.price=request.POST.get('price') product.desc=request.POST.get('desc') product.save()`

## Delete data from DB

> create a instance of the Model and find the one which you want to delete and then use ths `delete()` method on the instance and the data from the db relating to that id is deleted

# USER CREATION FORMS

- `from django.contrib.auth.forms import UserCreationForm`
