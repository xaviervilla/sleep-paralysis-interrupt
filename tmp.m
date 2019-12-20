myfile = csvread('/home/xvilla/Documents/2019fall/195/my classifier/myRecordings/0/overnight.txt');
myfile = myfile-myfile./2.0;
myfile = myfile+myfile*0.6;
writematrix(myfile(1:size(myfile,1)-1,:), '/home/xvilla/Documents/2019fall/195/my classifier/myRecordings/0/test.txt');