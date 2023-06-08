Image_to_Text
=============
Converting an image into text for representation.  


## Function   
> Converting an image into text for representation.  
> Allowing step-by-step scaling rate changes.
> Reading the brightness of an image and arranging special characters based on the differences in brightness.

## Image conversion function.
```C++
char colorToChar(Color C, int type) {

    //  밝기 = (2 * Red + 5 * Green + 1 * Blue) / 8
    int tempInt = (2 * C.r + 4 * C.g + C.b) / 8;    

    //왼쪽의 가장 어두운 것부터 오른쪽의 가장 밝은 것까지 선택하기 위한 문자 목록
    string CHARACTERS;

    switch (type) {
    case 1:
        CHARACTERS = "$@&X?Æ§0?8#1�‡/|(){}[]?li-_?ø%*±+÷~<>!;:,^°`'.· ";   
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

```
## Call the image transformation function after image recognition.
```C++
 int pixelsPerLetter;
    cout << "Pixels per letter: ";
    cin >> pixelsPerLetter;
    while (pixelsPerLetter > 100 || pixelsPerLetter < 1) {
        cout << "\tError: 1부터 100까지만 가능합니다 다시하세요: ";
        cin >> pixelsPerLetter;
    }

    int type;
    cout << "\n1. Complex:\t $@&X?Æ§0?8#1�‡/|(){}[]?li-_?ø%*±+÷~<>!;:,^°`'.· ";
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

```
