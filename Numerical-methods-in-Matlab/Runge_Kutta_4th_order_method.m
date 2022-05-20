% Runge-Kutta 4th order method for solving DE

function y = runge_kutta_4_method(f,a,b,n,y0)
    % Algorithm solves a starting point problem y' = f(x,y) with Runge-Kutta 4th order method
    % USAGE: y = runge_kutta_4_method(F, A, B, N, Y0);
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
    % Solving starting point problem
    for i = 2:n+1
      k1 = h*f(x(i-1),y(:,i-1));
      k2 = h*f(x(i-1)+h/2,y(:,i-1)+k1(:)/2);
      k3 = h*f(x(i-1)+h/2,y(:,i-1)+k2(:)/2);
      k4 = h*f(x(i-1)+h,y(:,i-1)+k3(:));
      y(:,i) = y(:,i-1)+(k1(:)+2*k2(:)+2*k3(:)+k4(:))/6;
    end
    % y = y(1,end);
end