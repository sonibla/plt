#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include <state.h>
#include <client.h>
#include <cstring>

using namespace std;
using namespace state;

int main(int argc,char* argv[])
{
    client::Test test;
    if (argc == 2) {
        if (strcmp(argv[1], "hello") == 0) {
            cout << "Hello world !" << endl;
        }else if (strcmp(argv[1], "state") == 0) {
            test.state();
        }else if (strcmp(argv[1], "render") == 0) {
            test.render();
        } else if (strcmp(argv[1], "engine") == 0) {
            test.engine();
        } else if (strcmp(argv[1], "random_ai") == 0) {
            //test.random_ai();
        } else if (strcmp(argv[1], "heuristic_ai") == 0) {
            //test.heuristic_ai();
        } else if (strcmp(argv[1], "rollback") == 0) {
            //test.thread();
        }else if (strcmp(argv[1], "deep_ia") == 0) {
            //test.thread();
        }else if (strcmp(argv[1], "thread") == 0) {
            //test.thread();
        }else if (strcmp(argv[1], "record") == 0) {
            //test.thread();
        }else if (strcmp(argv[1], "play") == 0) {
            //test.thread();
        }else if (strcmp(argv[1], "listen") == 0) {
            //test.thread();
        }else if (strcmp(argv[1], "network") == 0) {
            //test.thread();
        }else{
            cout << "Unknown argument" << endl;
        }
    } else {
        cout << "Too few or too many arguments" << endl;
    }

    return 0;
}
