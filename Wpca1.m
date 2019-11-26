function Y = Wpca1(X)
% Copyright (c) 2015, MathWorks, Inc.
    [~,Y] = pca(X,'NumComponents',1);
end