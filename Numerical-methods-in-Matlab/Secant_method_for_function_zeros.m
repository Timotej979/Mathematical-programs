% Secant method for finding function zeros

function [c, i] = secant_method_for_function_zeros(f, a, b, eps, iterLimit)
    % Algorithm of secant method for finding zeros of a function
    % USAGE: [xs, is] = secant_method_for_function_zeros(f, aproximation1, aproximation2, eps, iteration_num);
    format long
    i = 0;
    while(abs(b - a) >= eps)
        c = b - f(b) * (b - a)/(f(b) - f(a));
        a = b;
        b = c;
        if(i > iterLimit)
            break;
        end
        i = i + 1;
    end
end