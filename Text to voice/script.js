        const listenBtn = document.getElementById("listen");
        const textArea = document.getElementById("text");
        let speech = new SpeechSynthesisUtterance();
        let voices = [];
        let voiceSelect = document.getElementById("language");

        window.speechSynthesis.onvoiceschanged = () => {
            voices = window.speechSynthesis.getVoices();
            speech.voice = voices[0];

            voices.forEach((voice, i) => (voiceSelect.options[i] = new Option(voice.name, i)));
        };
        voiceSelect.addEventListener('change', () => {
            speech.voice = voices[voiceSelect.value]
        })

        listenBtn.addEventListener('click', () => {
            speech.text = textArea.value;
            window.speechSynthesis.speak(speech);
        })