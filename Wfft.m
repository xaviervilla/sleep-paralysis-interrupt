function Y = Wfft(X)
    Y = mean(real(fft(X)),2);
end