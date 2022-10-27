export const dataController = {
  addData(chart, data) {
    if (chart.config._config.type == "bar") {
      chart.data.datasets.forEach((dataset) => {
        for (const key in data) {
          if (typeof data[key] != "function") dataset.data.push(data[key]);
        }
      });
    } else {
      chart.data.datasets.forEach((dataset) => {
        for (const key in data) {
          if (typeof data[key] == "function") {
            dataset.data.push(data[key]());
            dataset.data.push(100 - data[key]());
          }
        }
      });
    }
  },
  removeData(chart) {
    chart.data.datasets.forEach((dataset) => {
      dataset.data = [];
    });
  },
};
