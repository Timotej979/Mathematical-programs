% Trapezoidal rule for solving DE

function y = trapezoidal_rule(f, a, b, n, y0)
    % Algorithm solves a starting point problem y' = f(x,y) with trapezoidal(implicit) rule
    % USAGE: y = trapezoidal_rule(F, A, B, N, Y0);
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
      z = y(:,i-1);
      for k = 1:100
        y(:,i) = y(:,i-1)+h/2*(f(x(i-1),y(:,i-1))+f(x(i),z));
        if abs((y(:,i)-z)/y(:,i)) < 1e-10
            break;
        end
        z = y(:,i);
      end
    end
    % y = y(1,end);
end