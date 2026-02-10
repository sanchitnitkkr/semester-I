const ctx = new AudioContext();
const sampleRate = ctx.sampleRate;

function playTone(freq, durationMs) {
  const osc = ctx.createOscillator();
  osc.type = 'sine';
  osc.frequency.value = freq;

  const gain = ctx.createGain();
  gain.gain.value = 0.3; // keep volume reasonable

  osc.connect(gain).connect(ctx.destination);
  osc.start();

  osc.stop(ctx.currentTime + durationMs / 1000);
}

async function sendBit(bit) {
  playTone(bit === 1 ? 19100 : 18800, 80);
  await new Promise(r => setTimeout(r, 100));
}

async function sendToken(bits) {
  for (const bit of bits) {
    await sendBit(bit);
  }
}

// Example
sendToken([1,0,1,1,0,0,1,0]);
