FROM node:alpine 

WORKDIR /usr/my-node-app

COPY ./package.json ./
RUN npm install


COPY ./ ./

CMD [ "npm","start" ]