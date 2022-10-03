# Creating a name CLI

- Create a repo for your CLI
- Create a npm account || to login from cli to your local machine

> create user uisng cli

- `npm adduser` || `npm login`

> Check your account

- `npm woami`

> To run your file directly from terminal give your file **+X** power to your file and give **#!node path**

- `#!/usr/bin/env node`

> Run you file with a **name** instead of **./index.js**. To this your need to register this package. To register this package run `npm init` or

     {

    	"name": "ali-intro",
    	"version": "1.0.0",
    	"bin": {
    	"ali-intro": "index.js"
    	}
    }

> **IMPORANT** run you file as a command you need bin object
> to run the local package in you local machine you need to **link** the package using `npm link`
> what `npm link` does it it install this package locally globally in the machine. This command is similar to `npm i -g package name`
> to unistall this package globally `npm uninstall -g ali-intro`

## PUBLISH CLI

> you need to be logged in and run `npm publish`
> npm.im/packagename to directly route to your package page

## Clear consolde

- `console.clear()`

## Ignore files

.gitongone

## Publish version

**Important** You cannot publish the same app with same version. NPM packages use semantic versioning

- major (Changes which can break prev version, or Major update) `npm version major`
- minor (new feautre added, but dosent break anything) `npm version minor`
- patch (nothing breaks) `npm version patch`

## Require package json file in js

> `const pjJSON=require("./package.json")` while imported js converts pjJSON file into js objecty

## Want no liscence use UNLCENSED

## CREATE a NODE MODULE

code of comnduct file use **conduct cli by sindresorhus**
license **licensed plibither8**
