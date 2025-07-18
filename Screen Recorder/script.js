const video = document.getElementById("recorded");
const stopBtn = document.getElementById("stop");
let recorder;
let chunks = [];
let stream;

async function startRecording() {
    stream = await navigator.mediaDevices.getDisplayMedia({ video: true });
    recorder = new MediaRecorder(stream);
    chunks = [];

    recorder.ondataavailable = (e) => chunks.push(e.data);

    recorder.onstop = () => {
        const blob = new Blob(chunks, { type: "video/webm" });
        const url = URL.createObjectURL(blob);
        video.src = url;
        video.play();

        const a = document.createElement('a');
        a.href = url;
        a.download = 'recording.webm';
        document.body.appendChild(a);
        a.click();
        document.body.removeChild(a);

        chunks = [];
        stopBtn.disabled = true;
    };

    recorder.start();
    stopBtn.disabled = false;
}

function stopRecording() {
    if (recorder && recorder.state === "recording") {
        recorder.stop();
        stream.getTracks().forEach((track) => track.stop());
    }
    stopBtn.disabled = true;
}
