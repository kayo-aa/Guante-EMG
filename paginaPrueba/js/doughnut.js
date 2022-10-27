export const porcentajeLS = localStorage.getItem("porcentaje");

export const dataLsDGH = {
  labels: ["% Total", "Sin completar"],
  datasets: [
    {
      label: "My First Dataset",
      data: [porcentajeLS, 100 - porcentajeLS],
      backgroundColor: ["rgba(107, 99, 211, 0.8)", "rgba(107, 99, 211, 0.5)"],
      hoverBackgroundColor: "rgba(107, 99, 211, 0.9)",
      hoverBorderColor: "rgba(107, 99, 211)",
      hoverOffset: 4,
      borderWidth: 4,
      borderColor: "rgba(107, 99, 211, 0.9)",
      borderRadius: 8,
      spacing: 4,
      circumference: 360,
      rotation: 0,
    },
  ],
};

export const configLsDGH = {
  type: "doughnut",
  data: dataLsDGH,
  options: {
    responsive: true,
    // aspectRatio: 1,
    maintainAspectRatio: false,
    layout: {
      padding: 16,
    },
    plugins: {
      legend: {
        display: true,
        position: "top",
        labels: {
          boxWidth: 30,
          boxHeight: 8,
        },
      },
    },
  },
};
