# Class Based Views

- List View
  `from django.views.generic import ListView`
- Detail View
  `from djando.views.generic import DetailView`

Note: When attaching Class view to path we need to send `views.ProductDetailView.as_view()`

- Create, Edit or Delete records we need to mport CreateView
  `from django.views.genric.edit import CreateView`
