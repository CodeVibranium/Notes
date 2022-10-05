# Level 1

> A django model(definitive store) is a representation of a table in a db.
> A class is a blueprint and to create a record create a instance of the class and send corresponding data to the model
> Data returned from a query will be queryset object and data inside queryset will be alist and list holds records as objects and each object is a instance of the model
> `from django.db import models`(models are imported from djando.db)

## Verbose filed name (Human readable)

> except fk, mamny to many fileds andone to one fields can take a option first arg verbose name.
> django replace \_ with spaces while creating table column name and djando admnin

## Primary Key

`brand_id= models.BigAutoField(primary_key=True)`

## Foriegn key

`product_id=models.ForiegnKey(Category:modelName,on_delete=models.CASCADE || models.PROTECT)`

## One to One R/S

`product=models.OneToOneField(Product,on_delete=models.CASCADE)`

## Differnece between fk and OneToOne

FK can be duplicate (for one category there can be many products) where as when you want the foriegn key to be unq in the entire table thyen we use OneToOne filed

## Many to Many R/S

A product can belong to multiple category and a category can be linked to multiple products
Djnago generating link table

## Model Meta options

Define the way of changing default behaviour of our model,

```class Meta:
		ordering=['author']
		verbose_name_plural=['categories']
```

## Insert Data into data base

Brand.objects.all()
Brand.objects.create() = creating instance and saving or (a=Brnad() && a.save())
Brand.objects.all().delete()
.save can update the row data but create() cannot()

## What is a treee query set
