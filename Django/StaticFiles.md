# Static Files

> In your App create a static folder
> And in that folder create a new folder with the name of the app
> And then create styles over there
> The Catch is for every change in static file you need to restart your server for changes to appear.
> To use any static files you need to load the static files `{load staticfiles}` at the top of your page.
> But the load static files was deprecated use `{load static} `instead.

> Django loads your staticfiles from installed apps `django.contrib.staticfiles`
> What ever content is not gonna change unless you change are static

> Use CDN buy using CDN we download bootstrap code into our browser.

## Base template

Base.html

```html
{% load static%}
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Food</title>
    <link
      href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css"
      rel="stylesheet"
    />
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/js/bootstrap.bundle.min.js"></script>
  </head>
  <body>
    <nav class="navbar navbar-dark bg-dark">
      <a class="navbar-brand">Food App</a>
      <div class="nav">
        <a href="#" class="nav-item nav-link">Add item</a>
        <a href="#" class="nav-item nav-link">Delete Item</a>
        <a href="#" class="nav-item nav-link">View item</a>
      </div>
    </nav>
    {% block body%} {% endblock %}
  </body>
</html>
```

index.html

```html
{% extends 'Items/base.html'%} {%block body%}

<h1>All Food Items</h1>
{% for item in items%}

<h1>
  <a href="{% url 'detail_view' item.id%}"> {{item.id}} {{item.name}} </a>
</h1>

{% endfor %} {% endblock %}
```
