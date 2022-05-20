% Leapfrog method for solving DE

 function y = leapfrog_method(f, a, b, n, y0)
    % Algorithm solves a starting point problem y' = f(x,y) with leapfrog method
    % USAGE: y = leapfrog_method(F, A, B, N, Y0);
    % INPUT DATA:
    % F is a given right-sided function
    % A, B are limits of DE
    % N number of subintervals 
    % Y0 starting point value in point a
    % OUTPUT DATA:
    % y aproximated value of function F in point B
    
    % Interval spliting
    h = (b-a)/n;
    x = linspace(a,b,n+1);
    y = zeros(length(y0),n+1);
    y(:,1) = y0(:);
    % First aproximation calculated with Euler method
    z = modeuler(f,a,a+h,1,y0);
    y(:,2) = z(:,end);
    % Solving starting point problem
    for i = 3:n+1
      y(:,i) = y(:,i-2)+2*h*f(x(i-1),y(:,i-1));
    end
    % y = y(1,end);
end