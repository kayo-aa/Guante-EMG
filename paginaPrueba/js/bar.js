export const dedosLS = localStorage.getItem("dedos").split(",");

const labels = ["Meñique", "Anular", "Mayor", "índice", "Pulgar"];

export const dataLsBar = {
  labels: labels,
  datasets: [
    {
      label: "Dedos",
      data: dedosLS,
      backgroundColor: "rgba(107, 99, 211, 0.85)",
      borderColor: "rgba(107, 99, 211)",
      borderRadius: 5,
      borderWidth: 3,
      hoverBackgroundColor: "rgba(107, 99, 211)",
      hoverBorderColor: "rgba(102, 94, 192)",
      inflateAmount: 0,
      barThickness: "flex",
      hidden: false,
      base: 0,
    },
  ],
};

export const configLsBar = {
  type: "bar",
  data: dataLsBar,
  options: {
    responsive: true,
    maintainAspectRatio: false,
    layout: {
      padding: 16,
    },
    scales: {
      x: {
        grid: {
          display: true,
          lineWidth: 2,
          color: "#3B3C43",
        },
      },
      y: {
        grid: {
          display: true,
          lineWidth: 2,
          color: "#3B3C43",
        },
      },
    },
    plugins: {
      legend: {
        display: true,
        position: "top",
        labels: {
          boxWidth: 30,
          boxHeight: 8,
          padding: 0,
        },
      },
      subtitle: {
        display: false,
        text: "hi",
      },
    },
  },
};
