% Tangent method for finding function zeros

function [r, i] = tangent_method_for_function_zeros(f, df, x0, eps, iterLimit)
    % Algorithm of tangent/Newton method for function zeros
    % USAGE: [xt, it] = tangent_method_for_function_zeros(f, df, aproximation, eps, iteration_num);
    format long
    i = 0;
    xn = x0;
    xm = xn - f(xn)/df(xn);
    while(abs(xm - xn) >= eps)
        xn = xm;
        xm = xn - f(xn)/df(xn);
        if(i > iterLimit)
            break;
        end
        i = i + 1;
    end
    r = xm;
end
