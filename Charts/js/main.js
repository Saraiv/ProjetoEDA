google.charts.load('current', {'packages':['gantt']});

var arrayData;
$(function(){
    $.get("exportar.csv", function(csvString) {
        arrayData = $.csv.toArrays(csvString, {onParseValue: $.csv.hooks.castToScalar});
    });
});

google.charts.setOnLoadCallback(function() {
    drawChart(arrayData);
});

function drawChart(arrayData){
    var container = document.getElementById('timeline');
    var chart = new google.visualization.Gantt(container);
    var dataTable = new google.visualization.DataTable();

    dataTable.addColumn("string", "Task ID");
    dataTable.addColumn("string", "ID da Máquina");
    dataTable.addColumn("string", "Job e Operação");
    dataTable.addColumn("date", "Começo");
    dataTable.addColumn("date", "Fim");
    dataTable.addColumn("number", "Duração");
    dataTable.addColumn("number", "Percent Complete");
    dataTable.addColumn("string", "Dependencies");

    dataTable.addRows(arrayData);

    var options ={
        timeline:{
            showRowLabels: true,
            colorByRowLabel: true
        },
        backgroundColor: '#ffd',
        legend:{ 
            position: 'above' 
        },
    };

    chart.draw(dataTable, options);

}