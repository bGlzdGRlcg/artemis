#include <bits/stdc++.h>
#include <windows.h>
#include <io.h>

using namespace std;

struct img{
    int x,y;
};

img getposes(string basefile,string facefile){
    ifstream base,face;
    base.open(basefile,ios::binary);
    face.open(facefile,ios::binary);
    base.seekg(53);
    face.seekg(53);
    int x,y,fx,fy;
    base>>x;
    base.get();
    base>>y;
    face>>fx;
    face.get();
    face>>fy;
    img sticker;
    sticker.x=abs(fx-x);
    sticker.y=abs(fy-y);
    base.close();
    face.close();
    return sticker;
}

img getpos(string basefile){
    ifstream base;
    base.open(basefile,ios::binary);
    base.seekg(53);
    int x,y;
    base>>x;
    base.get();
    base>>y;
    img sticker;
    sticker.x=x;
    sticker.y=y;
    base.close();
    return sticker;
}

int main(int argc,char* argv[]){
    img out;
    switch (argc) {
        case 2:
            out = getpos(argv[1]);
            printf("%d,%d",out.x,out.y);
        break ;
        case 3:
            out = getposes(argv[1],argv[2]);
            printf("%d,%d",out.x,out.y);
        break ;
        default:
            printf("usage:%s artemis image file name\n",argv[0]);
            printf("such as:%s test_face.png\n",argv[0]);
            printf("you can also put 2 files to get the relative coordinates\n");
            printf("such as:%s test_base.png test_face.png\n",argv[0]);
            printf("tips:more than 2 files are not supported");
        break ;
    }
    return 0;
}