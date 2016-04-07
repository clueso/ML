function [fvalue dX] = testfunc(X)
    fvalue = sum(X.^2);
    dX = 2*X;
end