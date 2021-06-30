from .models import File
from django.shortcuts import redirect, render
from django.views.generic import TemplateView

# Create your views here.
from django.http import HttpResponse

from .forms import FileForm
from .models import File

class Home(TemplateView):
    template_name = 'home.html'

def index(request):
    return render(request,'home.html')

def files(request):
    files = File.objects.all()
    return render(request,'files.html',{
        'files' : files
    })

def upload_file(request):
    if request.method == 'POST':
        form = FileForm(request.POST,request.FILES)
        if form.is_valid():
            form.save()
            return redirect('files')
    else:
        form = FileForm()
    return render(request,'upload.html',{
        'form' : form
    })
