async function getData() {
  return fetch("http://192.168.0.128/content", {

  }).then((response) => response.json());
}

let data = JSON.stringify(await getData().then());

let p= document.getElementById('content');

p.textContent = data
