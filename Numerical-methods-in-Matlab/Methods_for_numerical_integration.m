% Methods for numerical integration
% USAGE: y = name_of_function(F, A, B, N);
% INPUT DATA:
% F function to integrate
% A, B interval limits to integrate in-between
% N number of subdivisions on interval
% OUTPUT DATA:
% y evaluated valu of given integral

function S = rectangular_rule(f, a, b, n)
    format long
    h = (b-a)/n;
    x = linspace(a+h/2, b-h/2, n);
    y = f(x);
    w = ones(1, n);
    S = h*dot(w, y);
end

function S = trapezoidal_rule(f, a, b, n)
    format long
    h = (b-a)/n;
    x = linspace(a, b, n+1);
    y = f(x);
    w = [1 2*ones(1, n-1) 1];
    S = h/2*dot(w, y);
end

function S = simpson_13_rule(f, a, b, n)
    format long
    h = (b-a)/n;
    x = linspace(a, b, n+1);
    y = f(x);
    w = [1 4*ones(1, n-1) 1];
    w(3:2:end-2) = 2;
    S = h/3*dot(w, y);
end

function S = simpson_38_rule(f, a, b, n)
    format long
    h = (b-a)/n;
    x = linspace(a, b, n+1);
    y = f(x);
    w = [1 3*ones(1, n-1) 1];
    w(4:3:end-3) = 2;
    S = 3*h/8*dot(w, y);
end

function [S, A] = romberg_method(f, a, b, n)
    format long
    A = zeros(n);
    for i = 1:n
        A(i, 1) = trapezno_pravilo(f, a, b, 2^(i-1));
    end
    for j = 2:n
        for k = j:n
            A(k, j) = (4^(j-1)*A(k, j-1) - A(k-1, j-1))/(4^(j-1)-1);
        end
    end
    S = A(n,n);
end