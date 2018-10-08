#include <QCoreApplication>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>

using namespace std;

struct Point{
    float x;
    float y;
    char Name;
};

float distance(Point A, Point B);
float perimeter(Point Array[4]);

float area(Point Array[4]);//Geron
void writeFile (Point Array[], float &per, float &area);

QString printQuad(Point Array[4]);
int main()
{

    QFile resFile ("Result.txt");
    resFile.remove();

    Point quadOne[4];

        quadOne[0].Name='A';
        quadOne[0].x=0.0;
        quadOne[0].y=0.0;

        quadOne[1].Name='B';
        quadOne[1].x=4.0;
        quadOne[1].y=0.0;

        quadOne[2].Name='C';
        quadOne[2].x=4.0;
        quadOne[2].y=4.0;

        quadOne[3].Name='D';
        quadOne[3].x=0.0;
        quadOne[3].y=4.0;




    qDebug() << printQuad(quadOne);
    QString qsRetVal = "Quadrilateral with points: A[0;0] B[4;0] C[4;4] B[0;4] "  "Have perimeter %1 and area %2";
    float perim,ar;
    perim = perimeter(quadOne);
    ar = area(quadOne);
    qsRetVal = qsRetVal.arg(perim,0,'f',2).arg(ar,0,'f',3);
    qDebug() << qsRetVal;





   writeFile(quadOne, perim, ar);


}
QString printQuad(Point Arr[4])
{
    QString qsRetVal = "Quadrilateral with points: ";
    QString qsTemp;
    Point curPoint;
    for (int i=0; i<4; i++){
        qsTemp = "%1[%2;%3] ";
        curPoint = Arr[i];
        qsTemp=qsTemp.arg(curPoint.Name).arg(curPoint.x).arg(curPoint.y);
        qsRetVal.append(qsTemp);
    }
    return qsRetVal;
}


float distance(Point A, Point B){
    float dis = sqrt(pow((A.x-B.x),2) +pow((A.y-B.y),2));
    return dis;
    //return 4.0;
}


float perimeter(Point Array[4]){
    float per=0;
    for(int i=0;i<4;++i){
        per = per + distance(Array[i], Array[i+1]);
                i++;
        per= per+distance(Array[i],Array[0]);

    }
    //float per = distance(Array[0]+Array[1]+Array[2]+Array[3]);

    cout<<"The perimeter of the tetragon is " << per << ";" << endl;
    return per;
    //return 16.0;
}

float area(Point Array[4]){
    float area = abs(0.5*(Array[0].x*Array[1].y+Array[1].x*Array[2].y
            +Array[2].x*Array[3].y+Array[3].x*Array[0].y-
            Array[1].x*Array[0].y-Array[2].x*Array[1].y-
            Array[3].x*Array[2].y-Array[0].x*Array[3].y));
    /*int i = 0;
    float area = 0;
    while(i<l-1){
        area = area + (pArr[i].x*pArr[i+1].y-pArr[i+1].x*pArr[i].y);
        i++;
    }
    area = abs(0.5*(area + (pArr[i].x*pArr[0].y-pArr[0].x*pArr[i].y)));*/
    cout << "The total area of the tatragon is " << area << ";" << endl;
    return area;
    //return 16.0;
}

void writeFile (Point pArr[], float &per, float &area){
    QFile resFile ("result.txt");
    if (resFile.open(QFile::WriteOnly |QFile::Append )){
        QTextStream out(&resFile);
        out<<"Points coordinates\r\n";
        for (int i=0; i<4; i++){
            out<<"Point "<< i+1 <<": ["<<pArr[i].x<<";"<<pArr[i].y<<"]\r\n";
        }
        out << "The perimeter of the tetragon is "<< per << ";\r\n";
        out << "The total area of the tetragon is " << area << ";\r\n";

        out<<"\r\n";
    }}

