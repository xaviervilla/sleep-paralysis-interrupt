function promFreq = Wfreq(X)
    close all
    % Number of samples:
    numSamples = 64;
    % Number of seconds:
    numSeconds = 2;
    
    sampleFreq = numSamples/numSeconds;
    t = (0:numSamples-1)/sampleFreq;
    Y=X-mean(X(:, 1:64),2); % 100% this works correctly

%     figure
%     plot(t,Y)
%     title('Panic Breathing Signal with Noise')
%     xlabel('time (seconds)')
%     hold off
    
    Y = fft(Y,64,2);
    Pyy = zeros(size(Y,1),64);
    for i=1:size(Y,1)
        Pyy(i, :) = real(Y(i, :).* conj(Y(i, :)) / 64);
    end
    
    f = 32*(1:sampleFreq*numSeconds)/(sampleFreq*2);
    [~,loc] = max(Pyy,[],2);
    promFreq = zeros(size(X,1),1);
    for i=1:size(X,1)
        promFreq(i) = f(loc(i));
    end
    

%     figure
%     plot(f(1:32),Pyy(1:32))
%     hold on
%     plot(f(loc),pk,'or')
%     title('Frequency component of Panic Breathing')
%     xlabel('frequency (Hz)')
    
end





