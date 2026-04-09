let processes = [];
let mode = "";

function createProcesses() {
    let n = document.getElementById("num").value;
    processes = [];

    for (let i = 1; i <= n; i++) {
        processes.push({ id: i, alive: true });
    }

    render();
    document.getElementById("instruction").innerText = "Select Mode";
}

function setMode(m) {
    mode = m;

    if (mode === "fail") {
        document.getElementById("instruction").innerText = "Click a process to FAIL";
    } else {
        document.getElementById("instruction").innerText = "Click a process to START election";
    }
}

function handleClick(id) {
    if (mode === "fail") {
        simulate(id, null);
    } else {
        simulate(null, id);
    }
}

function simulate(fail_id, initiator) {
    fetch("/simulate", {
        method: "POST",
        headers: {"Content-Type": "application/json"},
        body: JSON.stringify({ processes, fail_id, initiator })
    })
    .then(res => res.json())
    .then(data => {
        processes = data.processes;

        appendLogs(data.logs, "logsBox");
        appendLogs(data.internal, "internalBox");

        processes.forEach(p => {
            p.leader = (p.id === data.coordinator);
        });

        render();
    });
}

function appendLogs(logs, box) {
    let el = document.getElementById(box);
    logs.forEach(l => {
        el.innerHTML += l + "<br>";
    });
}

function render() {
    let container = document.getElementById("processContainer");
    container.innerHTML = "";

    processes.forEach(p => {
        let div = document.createElement("div");

        div.className = "process " +
            (p.leader ? "leader" : p.alive ? "alive" : "dead");

        div.innerText = "P" + p.id;
        div.onclick = () => handleClick(p.id);

        container.appendChild(div);
    });
}

function restart() {
    processes = [];
    document.getElementById("processContainer").innerHTML = "";
    document.getElementById("logsBox").innerHTML = "";
    document.getElementById("internalBox").innerHTML = "";
    document.getElementById("instruction").innerText = "Start from Step 1";
}
