/**
 This function converts a color to a character. Based off:
 http://paulbourke.net/dataformats/asciiart/
 @Param 1:	The color
 @Return:	The character
 */

/*
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>     
#include <fstream>      

using namespace std;
using namespace sf;




	//기능 구현
char colorToChar(Color C, int type = 2) {

    //  밝기 = (2 * Red + 5 * Green + 1 * Blue) / 8
    int tempInt = (2 * C.r + 4 * C.g + C.b) / 8;    //convert the pizel to black and white (get the intensity of the color)

    //왼쪽의 가장 어두운 것부터 오른쪽의 가장 밝은 것까지 선택하기 위한 문자 목록
    string CHARACTERS;

    switch (type) {
    case 1:
        CHARACTERS = "$@&X?Æ§0?8#1€‡/|(){}[]?li-_?ø%*±+÷~<>!;:,^°`'.· ";   
        break;
    case 2:
        CHARACTERS = "@#%*=+-:. ";                                      
        break;
    case 3:
        CHARACTERS = "$?.  ";                                            
        break;
    }


    int tempIndex = int((tempInt / 255.0) * CHARACTERS.length());

    return (CHARACTERS[tempIndex]);
}





int main() {

    cout << ". . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n";

    string imagePath;
    cout << "변환하려는 이미지 파일의 주소를 입력하세요 ->";
    getline(cin, imagePath);

   Image img;
    if (!img.loadFromFile(imagePath.c_str())) {
        return EXIT_FAILURE;
    }
    else {
        cout << "이미지 출력: " << imagePath << "\n";
    }

    string textFilePath = imagePath;

    for (int i = 0; i < 3; i++) {
        textFilePath.pop_back();      
    }
    textFilePath.append("txt");       

    ofstream outputTextFile(textFilePath, ios::trunc);	//텍스트 파일 저장 불가
    if (!outputTextFile) {
        cout << "텍스트 파일을 만들지 못했습니다. :(\n";
        return EXIT_FAILURE;
    }
    else {
        cout << "텍스트 파일 저장 주소: " << textFilePath << "\n";
    }
    cout << "\n. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .\n";

    int pixelsPerLetter;
    cout << "Pixels per letter: ";
    cin >> pixelsPerLetter;
    while (pixelsPerLetter > 100 || pixelsPerLetter < 1) {
        cout << "\tError: 1부터 100까지만 가능합니다 다시하세요: ";
        cin >> pixelsPerLetter;
    }

    int type;
    cout << "\n1. Complex:\t $@&X?Æ§0?8#1€‡/|(){}[]?li-_?ø%*±+÷~<>!;:,^°`'.· ";
    cout << "\n2. Simple:\t @#%*=+-:. ";
    cout << "\n3. Currency:\t $?.  ";
    cout << "\n - Choose a scale: ";
    cin >> type;

    while (type > 3 || type < 1) {
        cout << "\tError: 1부터 3까지만 가능합니다 다시하세요: ";
        cin >> pixelsPerLetter;
    }

    Color tempColor;
    for (int y = 0; y < img.getSize().y; y = y + pixelsPerLetter) {
        for (int x = 1; x < img.getSize().x; x = x + pixelsPerLetter) {
            tempColor = img.getPixel(x, y);
            outputTextFile << colorToChar(tempColor, type) << " ";
        }
        outputTextFile << "\n";
    }

    outputTextFile.close();
    std::cout << "\n성공했습니다 파일이 저장되었습니다: " << textFilePath << "\n\n";

    return EXIT_SUCCESS;
}


*/