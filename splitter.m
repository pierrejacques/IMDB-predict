function [out]=splitter(in)
tmp = {};
for i=1:length(in)
    str=in(i);
    spl=regexp(str,'\|','split');
    for j=1:length(spl)
        tmp=[tmp,spl{j}];
    end
end

out=unique(tmp);