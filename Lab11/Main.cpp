/*

  Zadanie z programowania obiektowego.
  Twoim zadaniem na dzisiejszych zajęciach jest przygotowanie metod pozwalających na wyświetlanie i zarządzanie ścieżkami względnymi pomiędzy dwoma
  punkitami w systemie plików ()
  Kolejnym zadaniem jest przygotowanie softlinku który przy wyświetlaniu pokaże ścieżkę do pliku do którego prowadzi.

  Ostateczny program powinien byc przyjazny dla programisty (miec czytelny i dobrze napisany kod),
  oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

  Program wyjściowy powinien składać się z czytelnego kodu. Powinna być spełniona zasada D.R.Y. - Don’t Repeat Yourself.

  Zadania oceniane są wg algorytmu:
      Warunkiem przystąpienia do oceniania programu jest jego poprawna kompilacja (bez błędów).
      Dokumentacja - 1 pkt.
      Poprawna kompilacja (bez ostrzeżeń) - 2 pkt.
      Poprawne wykonanie (odpowiednie wyjście, brak wycieków pamięci itp.) - 3 pkt.
      Ocena kodu (pod względem projektowym, zgodności z OOP, przejrzystości oraz sposobu implantacji) - maks. 4 pkt.

  Programy niezgodne z tematem/celem zadania, 
  ale kompilujące się (i dające potencjalnie "poprawne" wyjście) będą oceniane na 0 pkt.

*/

// TODO: Your includes here
#include "Dir.h"
#include "File.h"
#include "FSElement.h"
#include "Link.h"
#include "Type.h"
#include "User.h"
#include "Utils.h"
#include "SoftLink.h"
#include "Add.h"


/**
 * 
 * 
 * PRACOWALISMY W 2 OSOBY:
 * ANDRZEJ SWIETEK
 * MAKS WALICKI
*/
int main() {

  Dir* top = new Dir(".");
  Dir* home = new Dir("home");
  *top += home; // dodajemy do kat TOP podkatalog
  *home += new Dir("ewa");
  *home += new File("proj.descr");
  home->add(new File("proj.files.repo") );
  home->add(new Dir("adam") );
  
  top->findDir("ewa")->add( new Dir("Desk") );

  Dir* ewa = home->findDir("ewa");  
  // TODO: Store this file in some way... 
  File* STORE_THIS_FILE_v1; 
  STORE_THIS_FILE_v1 = new File("pict.jpg");
  *ewa += STORE_THIS_FILE_v1; 
  top->findDir("ewa")->add( new Dir("work") );

  top->findDir("adam")->add(new Dir("Cat_Pictures"));
 
  *top += add(
    new softLink(top->findDir("ewa")->findDir("Desk"), "MY_LINK"), "alt_Desk"
  );


  Dir* cats = top->findDir("adam")->findDir("Cat_Pictures");

  File* STORE_THIS_FILE_v2; 
  STORE_THIS_FILE_v2 = new File("cat1.jpg");
  *cats += STORE_THIS_FILE_v2;

  std::cout << *top << std::endl;

  std::cout << "--------------" << std::endl;

  std::cout << "Relative Path: " << std::endl;

  ShowRelativePaths(top, STORE_THIS_FILE_v2);

  std::cout << "--------------" << std::endl;
  top->listDirs(1);
  std::cout << "--------------" << std::endl;
  top->listDirs(3);




  delete top;
}

/*
. (DIR)
  home (DIR)
    ewa (DIR)
      Desk (DIR)
      pict.jpg (FILE)
      work (DIR)
    proj.descr (FILE)
    proj.files.repo (FILE)
    adam (DIR)
      Cat_Pictures (DIR)
        cat1.jpg (FILE)
    alt_desk (SOFTLINK) -> . home ewa Desk

Relative Path:
./home/admam/Cat_Pictures/cat1.jpg

//TODO: Spróbujcie wymyślić jak przedstawić ściężkę względną pomiędzy STORE_THIS_FILE_v1 a STORE_THIS_FILE_v2!
// (Bo nawet nie wiem jak to sobie wyobrazić.)


--------------
. home 
--------------
. home ewa Desk work adam Cat_Pictures
*/