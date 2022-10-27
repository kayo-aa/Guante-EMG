import { configLsDGH } from "./doughnut.js";
import { configLsBar } from "./bar.js";

Chart.defaults.font = {
  family: "'Ubuntu', 'Helvetica', 'Arial', sans-serif",
  size: 16,
  style: "normal",
  lineHeight: 1.2,
  weight: null,
};
Chart.defaults.color= "#FFF"

const chartFingerLs = new Chart(
  document.getElementById("ls--fingers"),
  configLsBar
);
const chartTotalLs = new Chart(
  document.getElementById("ls--total"),
  configLsDGH
);

export const chartFingerEsp = new Chart(
  document.getElementById("esp--fingers"),
  configLsBar
);
export const chartTotalEsp = new Chart(
  document.getElementById("esp--total"),
  configLsDGH
);



