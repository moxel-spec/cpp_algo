#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//BUBBLE SORT START
void bubbleSort(vector <int>&v, int size) {           //n elements    O(n*n)== O(n^2)
    for(auto i = 0; i < v.size(); i++) {               // n
        for(auto j = 0; j < v.size() - i - 1; j++) {     // n 
            if(v[j] > v[j+1]) {                           // 
                auto tmp = v[j];                         // 
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
}
//bubble SORT END

//INSERTION SORT START
template <typename T>
void gnome_sort(std::vector<T> &a, int size)     //n elements, and n-1 repeats.    (n-1) + (n-2) +..+1 == O(n^2)
{
    for (int i = 0; i + 1 < size; ++i) 
          if (a[i] > a[i + 1])             
        {
            std::swap(a[i], a[i + 1]);
            if (i != 0) // n
             i -= 2; //вычитается два и потом прибавляется один
        }
}
//INSERTION SORT END

// Функция быстрой сортировки
void quickSort(vector <int> &arr, int left, int right) {      //O(n*log(n))
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];                // O(n)
 
   
    while (i <= j) {
        while (arr[i] < pivot)                         // n
            i++;
        while (arr[j] > pivot)                          // n
            j--;
        if (i <= j) {                                   
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }                                                     // T(n)=a⋅T(n/b)+fn;
    };
 
    
    if (left < j)                                    //a=2,b=2,n^ log b (a)=n.   f(n)=n 
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);                     // O(n^log b (a)=n)
    
}

//СОРТИРОВКА ВЫБОРОМ
void SelectSort(vector <int>&v, int size)    //(n-1)+(n-2)+..+1 = sum 1..(n-1)[i] == 1/2(n^2-n) == O(n^2)
{
  int j = 0;
  int tmp = 0;
  for(int i=0; i<size; i++){    //n              
    j = i;
    for(int k = i; k<size; k++){      //n         
      if(v[j]>v[k]){
        j = k;
      }
    }
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
  }
}
//СОРТИРОВКА ВЫБОРОМ

//СОРТИРОВКА РАСЧЕСКОЙ
void CombSort(vector <int>&v, int size )      // O(n^2)
{
  int jump = size;
  bool swapped = true;
 
  while (jump > 1 || swapped)   // n
  {
    if (jump > 1)
      jump = (int)(jump / 1.25);
    swapped = false;
    for (int i = 0; i + jump < size; i++)   // n
      if (v[i] > v[i + jump])
        std::swap(v[i],v[i + jump]), swapped = true;
  }
}
//СОРТИРОВКА РАСЧЕСКОЙ


int main ()
{
srand (time(NULL));
double time1;//сортировка вставками
double time2;
double time3;
double time4;

double time_1;//сортировка пузырьками
double time_2;
double time_3;
double time_4;

double _time_1;//быстрая сортировка
double _time_2;
double _time_3;
double _time_4;

double __time_1;//сортировка выборкой
double __time_2;
double __time_3;
double __time_4;

double __time__1;//сортировка расческой
double __time__2;
double __time__3;
double __time__4;


int menu;
cout << "Открыть файл с рандомными  неотсортированными числами  " << endl;
cout << "Открыть файл с наполовину отортированными числами  " << endl;
cout << "Открыть файл с обратно отсортированными числами " << endl;
cout << "Открыть файл полностью с отсортированными числами" << endl;
cout << " " << endl;
while (true)
  {
    cin >> menu;
    switch(menu)
    {
       case 1:
       {
         cout <<  "Открыт файл с рандомными неотсортированными числами!" << endl;         
         ofstream out ("/home/maxon/Рабочий стол/C++/NoSorted");      
         long int integers;   
         cout << "Введите сколько чисел хотите записать в файл: " << endl; cin >> integers;
         
         for (int i =0;i<integers;i++)
           out << i*rand () % 120 << " ";
           
         cout << "Числа успешно записаны!"<< endl;
        
         out.close();
         ifstream fin ("/home/maxon/Рабочий стол/C++/NoSorted");
         vector <int> NoSorted;
         int number;
         
         if (!fin.is_open())
            cout << "File is not opened! " << endl;
         else 
            {
         while(fin >> number)
            NoSorted.push_back(number);
            
        for (auto i=NoSorted.begin();i!=NoSorted.end();i++)
            cout << *i << " ";
        cout << endl ;
            
            cout << "Размерность вектора: "<< NoSorted.size();
            cout << endl;
         }
        int size = NoSorted.size();
        clock_t t = clock();
        
            gnome_sort(NoSorted,NoSorted.size());
           
            cout << endl;
            cout << "Сортровка гномья заняла: : " << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            time1= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд " ;
            cout << endl;
            
            t = clock();
            bubbleSort(NoSorted,size);
            cout << "Сортировка пузырьковая заняла: " << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            time_1= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд " ;
            cout << endl;
             t = clock();
            quickSort(NoSorted,0,(NoSorted.size()-1));
            cout << "Быстрая сортировка заняла: " << endl;
            
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            _time_1= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд " ;
            cout << endl;
            t = clock();
            SelectSort(NoSorted,NoSorted.size());
            cout << "Сортировка выборкой заняла: " << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            __time_1= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд " ;
            cout << endl;
            t = clock();
            CombSort(NoSorted,NoSorted.size());
            cout << "Сортировка расческой заняла: " << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            __time__1= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд " ;
            cout << endl;
            
            cout << "Отсортированный вектор: " << endl;
            for (auto i=NoSorted.begin();i!=NoSorted.end();i++)
                cout << *i << " ";
            cout << endl ;
            
            cout << "Работа с рандомными неотсортрованными числами завершена! " << endl;     
       break;
         
         break;
       }
       case 2:
       {
       cout << "Открыт файл с наполовину отсортированными числами " << endl;
       ofstream out("/home/maxon/Рабочий стол/C++/HalfSorted");
       cout << "Введите количество чисел,которые хотите записать в файл: " << endl;
       long int integers1;
       cin >> integers1;
       for (int i =0;i<(integers1)/2;i++)
        out << i << " " ;
       for (int i =(integers1)/2;i<integers1;i++)
        out << i* rand() % 300 << " ";
       
       out.close();
       vector<int>buff2;
       int number2;
       ifstream fin ("/home/maxon/Рабочий стол/C++/HalfSorted");
         if (!fin.is_open())
            cout << "File is not opened! " << endl;
         else 
         {
             while (fin >> number2)
                buff2.push_back(number2);
                
             for (auto i=buff2.begin();i!=buff2.end();i++)
                cout << *i << " ";
                
                cout << endl ;
                cout << "Размерность вектора : "<< buff2.size();
                cout << endl;
         }
         int size1 = buff2.size();
         clock_t t =clock();
         
         gnome_sort(buff2,buff2.size());
         cout << "Сортировка гномья заняла : " << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            time2= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд";
            cout << endl;
            
            t=clock();
            bubbleSort(buff2,size1);
            cout << "Сортировка пузырьковая заняла: " << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            time_2= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд";
            cout << endl;
            
            t=clock();
            quickSort(buff2,0,(buff2.size()-1));
            cout << "Быстрая сортировка заняла: " << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            _time_2= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд " ;
            cout << endl;
            t =clock();
            SelectSort(buff2,buff2.size());
            cout << "Сортировка выборкой заняла:" << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            __time_2= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд " ;
            cout << endl;
            t = clock();
            CombSort(buff2,buff2.size());
            cout << "Сортировка расческой заняла: " << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            __time__2= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд " ;
            cout << endl;
            cout << "Отсортированный вектор: " << endl;
         for (auto i = buff2.begin();i!=buff2.end();i++)
            cout << *i << " ";
         cout << endl;

            cout << endl;
            cout << "Работа с наполовину отсортрованными числами завершена! " << endl;
         
         break;
       }
       case 3:
       {
       cout << "Открыт файл с обратно отсортиованными числами " << endl;
       ofstream out ("/home/maxon/Рабочий стол/C++/ReverseSorted");
       cout << "Введите количество чисел,которые хотите добавить в файл: " << endl;
       long int integers3;
       cin >> integers3;
       for (int i =integers3;i>=0;i--)
            out << i << " ";
       out.close();
       vector <int>buff3;
       int numbers;
       ifstream fin ("/home/maxon/Рабочий стол/C++/ReverseSorted");
         if (!fin.is_open())
            cout << "File is not opened! " << endl;
         else 
         {
             while(fin>>numbers)
                buff3.push_back(numbers);

             for (auto i=buff3.begin();i!=buff3.end();i++)
                cout << *i << " ";
            cout << endl ;
            
            cout << "Размерность вектора: "<< buff3.size();
            cout << endl;
         }
         int size3 = buff3.size();
         clock_t t =clock();
         
         gnome_sort(buff3,buff3.size());
         cout << "Сортировка гномья заняла: " << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            time3= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд";
            cout << endl;
            t=clock();
            
            bubbleSort(buff3,size3);
            cout << "Сортировка пузырьковая заняла: " << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            time_3= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд";
            cout << endl;
            t=clock();
            
            quickSort(buff3,0,(buff3.size()-1));
            cout << "Быстрая сортировка заняла: " << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            _time_3= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд " ;
            cout << endl;
            t = clock();
            SelectSort(buff3,buff3.size());
            cout << "Сортировка выборкой заняла: " << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            __time_3= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд " ;
            cout << endl;
            
            t = clock();
            CombSort(buff3,buff3.size());
            cout << "Сортировка расческой заняла: " << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            __time__3= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд " ;
            cout << endl;
            cout << "Отсортированный вектор: " << endl;
         for (auto i =buff3.begin();i!=buff3.end();i++)
            cout << *i << " ";
         cout << endl;

         break;
       }
       case 4:
       {
       cout << "Открыт файл  уже с отсортированными числами " << endl;
       ofstream out ("/home/maxon/Рабочий стол/C++/Sorted");
       long int integers4;
       cout << "Введите количество чисел,которые хотите добавить в файл: "<< endl;
       cin >> integers4;
       for (int i =0;i<integers4;i++)
          out << i << " ";
       out.close();
       vector<int>buff4;
       int numbers1;
        ifstream fin ("/home/maxon/Рабочий стол/C++/Sorted");
         if (!fin.is_open())
            cout << "File is not opened! " << endl;
         else 
         {
             while(fin>>numbers1)
                buff4.push_back(numbers1);
             for (auto i=buff4.begin();i!=buff4.end();i++)
                cout << *i << " ";
            cout << endl ;
            
            cout << "Размерность вектора: "<< buff4.size();
            cout << endl;
         }
         int size4 = buff4.size();
         clock_t t =clock();
         
         gnome_sort(buff4,buff4.size());
         cout << "Сортировка гномья заняла: " << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            time4= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд";
           cout << endl;
           
           t =clock();
           bubbleSort(buff4,size4);
           cout << "Сортировка пузырьковая заняла: " << endl;
           std::cout.setf(std::ios::fixed,std::ios::floatfield);
            time_4= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд";
           cout << endl;
           
           t=clock();
           quickSort(buff4,0,(buff4.size()-1));
           cout << "Быстрая сортировка заняла: " << endl;
           std::cout.setf(std::ios::fixed,std::ios::floatfield);
            _time_4= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд";
           cout << endl;
           t=clock();
           SelectSort(buff4,buff4.size());
           cout << "Сортировка выборкой заняла: " << endl;
           std::cout.setf(std::ios::fixed,std::ios::floatfield);
            __time_4= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд " ;
            cout << endl;
            
            t = clock();
            CombSort(buff4,buff4.size());
            cout << "Сортировка расческой заняла: " << endl;
            std::cout.setf(std::ios::fixed,std::ios::floatfield);
            __time__4= (static_cast<double>(clock() - t) / CLOCKS_PER_SEC);
            
            cout << (static_cast<double>(clock() - t) / CLOCKS_PER_SEC) << " секунд " ;
            cout << endl;
         for (auto i=buff4.begin();i!=buff4.end();i++)
            cout << *i << " ";
         cout << endl;
            
         break;
       }
       case 5: 
       {
       
         cout << "Результат выполнения  сортировки файла с неотсортированными числами: " << endl;
         cout <<"1.Сортировка гномья: \t\t" << time1 << endl;
         cout <<"2.Сортировка пузырьками: \t" << time_1 << endl;
         cout <<"3.Быстрая сортировка: \t\t" << _time_1<< endl;
         cout <<"4.Сортировка выборкой: \t\t" << __time_1<< endl;
         cout <<"5.Сортировка расческой: \t"<< __time__1;
         cout << endl;
         cout << "Результат выполнения сортировки файла с наполовину отсортированными числами: "<< endl;
         cout <<"1.Сортировка гномья: \t\t"<< time2 << endl;
         cout <<"2.Сортировка пузырьками: \t" << time_2<< endl;
         cout <<"3.Быстрая сортировка: \t\t"<< _time_2<< endl;
         cout <<"4.Сортировка выборкой: \t\t"<< __time_2<< endl;
         cout <<"5.Сортировка расческой: \t"<< __time__2;
         cout << endl;
         cout << "Результат выполнения сортировки файла с обратно отсортированными числами: " << endl;
         cout <<"1.Сортировка гномья: \t\t"<< time3<< endl;
         cout <<"2.Сортировка пузырьками: \t" << time_3<< endl;
         cout <<"3.Быстрая сортировка: \t\t"<<_time_3<< endl;
         cout <<"4.Сортировка выборкой: \t\t"<< __time_3<< endl;
         cout <<"5.Сортировка расческой: \t"<< __time__3;
         cout << endl;
         cout << "Результат сортировки файла с отсортированными файлами: " << endl;
         cout <<"1.Сортировка гномья: \t\t"<< time4<< endl;;
         cout <<"2.Сортировка пузырьками: \t" << time_4 << endl;
         cout <<"3.Быстрая сортировка: \t\t" << _time_4<< endl;
         cout <<"4.Сортировка выборкой: \t\t"<< __time_4<< endl;
         cout <<"5.Сортировка расческой: \t"<< __time__4;
         cout << endl;
        
         break;
       }
    }
  }
}
