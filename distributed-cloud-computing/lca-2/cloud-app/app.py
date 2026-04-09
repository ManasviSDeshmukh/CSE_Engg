from flask import Flask, render_template, request, jsonify

app = Flask(__name__)

@app.route("/")
def home():
    return render_template("index.html")

@app.route("/simulate", methods=["POST"])
def simulate():
    data = request.json
    processes = data["processes"]
    initiator = data.get("initiator")
    fail_id = data.get("fail_id")

    logs = []
    internal = []

    # Apply failure
    if fail_id:
        for p in processes:
            if p["id"] == fail_id:
                p["alive"] = False
                logs.append(f"Process {fail_id} FAILED")

    active = [p for p in processes if p["alive"]]

    if not active:
        return jsonify({"logs": ["No active processes"], "internal": [], "coordinator": None})

    # Election
    starter = initiator if initiator else active[0]["id"]

    logs.append(f"Process {starter} starts election")

    for p in active:
        if p["id"] > starter:
            logs.append(f"Process {starter} -> ELECTION -> Process {p['id']}")
            internal.append(f"[internal] Process {p['id']} responds OK")

    coordinator = max([p["id"] for p in active])
    logs.append(f"Process {coordinator} becomes COORDINATOR")

    for p in active:
        if p["id"] != coordinator:
            internal.append(f"[internal] Coordinator informs Process {p['id']}")

    return jsonify({
        "logs": logs,
        "internal": internal,
        "coordinator": coordinator,
        "processes": processes
    })

if __name__ == "__main__":
    app.run(debug=True)