#include "queueTP.hxx"
#include "worker.hxx"

#include <cstring>
#include <iostream>

constexpr const char* chooseStr{"WSMEwsme"};
constexpr int sizeQueue{5};

void confirmChoose(char choice);
Worker* setWorker(char choice, Worker* worker);



int main(){

    QueueTp<Worker*> workingQueue;
    Worker* tempWorker;

    for(int it = DEFVALUE; it < Q_SIZE; it++){
        char choice;
        std::cout << "Choose a type of worker: " << std::endl;
        std::cout << "W for waiter, \n";
        std::cout << "S for singer, \n";
        std::cout << "M for singingwaiter \n";
        std::cout << "E for exit" << std::endl;

        std::cin >> choice;
        confirmChoose(choice);
        if(choice == 'e' || choice == 'E'){
            break;
        }
        tempWorker = setWorker(choice, tempWorker);

        std::cin.get();
        tempWorker->Set();
        
        workingQueue.enqueue(tempWorker);

    }

    for(int it = 0; it < workingQueue.queueCount(); it++){

            std::cout << std::endl;

            workingQueue.dequeue(tempWorker);
            tempWorker->Show();
            delete tempWorker;
    }

    return EXIT_SUCCESS;
}

void confirmChoose(char choice){
    while(strchr(chooseStr, choice) == DEFVALUE){
           std::cout << "Enter W, S, M, E" << std::endl;
           std::cin >> choice; 
    }
}

Worker* setWorker(char choice, Worker* worker){
        switch(choice){

        case 'W':
        case 'w':
            worker = new Waiter;
            return worker;
        case 'S':
        case 's':
            worker = new Singer;
            return worker;
        case 'M':
        case 'm':
            worker = new SingingWaiter;
            return worker;
        default:
            return 0;    
        }
}
