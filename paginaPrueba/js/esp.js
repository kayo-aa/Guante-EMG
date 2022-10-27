import { chartFingerEsp, chartTotalEsp } from "./index.js";
import { dataController } from "./data.service.js";
function getPorcentaje() {
  return (
    (this.menique + this.anular + this.mayor + this.indice + this.pulgar) / 5
  );
}

async function showEspData() {
  const response = await fetch(
    "https://rickandmortyapi.com/api/chhharacter/434",
    {}
  );

  let myData = {};
  if (!response.ok) {
    myData = {
      menique: 0,
      anular: 0,
      mayor: 0,
      indice: 0,
      pulgar: 0,
    };
  } else {
    myData = await response.json();
  }
  myData.getPorcentaje = getPorcentaje;

  dataController.removeData(chartFingerEsp);
  dataController.addData(chartFingerEsp, myData);
  dataController.removeData(chartTotalEsp);
  dataController.addData(chartTotalEsp, myData);

  if (myData.getPorcentaje() != 0) {
    chartFingerEsp.data.datasets[0].hidden = false;
    chartTotalEsp.data.datasets[0].hidden = false;
  } else {
    chartFingerEsp.data.datasets[0].hidden = true;
    chartTotalEsp.data.datasets[0].hidden = true;
  }
  chartFingerEsp.update();
  chartTotalEsp.update();

  if (response.ok) { //para que si la respuesta no fue válida, no escriba valores de 0 en el localStorage
    localStorage.setItem("dedos", chartFingerEsp.data.datasets[0].data.toString());
    localStorage.setItem("porcentaje", chartTotalEsp.data.datasets[0].data[0].toString());
  }
}


showEspData();
