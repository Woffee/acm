{
	ID: jinyu121
	PROG:邻接表的读入
	LANG: PASCAL
}
const
    filename='';
    inf=filename+'.in';
    ouf=filename+'.out';
    oo=168430090;       //fillchar(10)的结果

type
    node=record oud,start:longint;end;
    side=record y,v,next:longint;end;

var
    n,m:longint;
    i,j,k:longint;
    v:array[1..1000] of node;
    e:array[1..3000] of side;
    now,xx,yy,vv:longint;
begin
randomize;
assign(input,inf);reset(input);
//assign(output,ouf);rewrite(output);
    fillchar(v,sizeof(v),0);
    fillchar(e,sizeof(e),0);
    now:=0;

    //读入数据
    readln(n,m);
    for i:=1 to m do
        begin
            readln(xx,yy,vv);
            e[i].y:=yy;e[i].v:=vv;      //把读入的数据放进“边的记录”中
            e[i].next:=v[xx].start;     //这条记录指向这个点的“上一条点记录”
            v[xx].start:=i;             //“点的记录”的开头指向这条记录
            inc(v[xx].oud);             //增加出度
        end;


close(input);
close(output);
end.