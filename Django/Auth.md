# Authentication

## Create a view to register users

> `from django.config.auth.forms import UserCreationForm` > `from django.contrib import messages`

```python
def register(request):
	if request.method=="POST":
		form=UserCreationForm(request.POST)
		if form.is_valid():
			username=form.cleaned_data.get('username')
			messages.success(request,f'Welcome {username}, you have signed in successfully')
			return redirect("all_items")
	else:
		form=UserCreationForm()
	return render(request,'users/register.html',{'form':form})
```

## Save users

```python
		**form.save()**
```

## ADD Additional Fields (like email)

> You need to extend the **FORM**
> You need to create your own class form whioch will inherit from **_UserCreationForm_**

```python
class RegisterUserForm(UserCreationForm):
	email=forms.EmailField()
	firstname=forms.CharField(max_length=40)
	lastname=forms.CharField(max_length=40)
	class Meta:
		# Class which provides information about this class
		model=User
		fields=['username','email','firstname','lastname','password1','password2']
```

## Login View

```python
from django.contrib.auth import views as auth_views
path('login',auth_views.LoginView.as_view(template_name='user/login/.html'),name='login')
path('login',auth_views.LogoutView.as_view(),name='logout')

        <!-- {% if user.is_authenticated %}
        <a href="{% url 'logout' %}" class="nav-item nav-link">Logout</a>
        {% else %}
        <a href="{% url 'login' %}" class="nav-item nav-link">Login</a>
        { % endif %} -->
```

## Restricting routes

In Views
from django.contrib.auth.decorators import login_required
@login_required
