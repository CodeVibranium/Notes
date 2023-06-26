FROM node:18

WORKDIR /visits-app
COPY ./package.json ./
RUN npm install

COPY ./ ./
CMD [ "npm","start" ]