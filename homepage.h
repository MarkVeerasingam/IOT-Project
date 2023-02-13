String homePagePart1 = F(R"====(
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width,initial-scale=1">
        <title>IOT Guitar Pedal</title>
        <style>
            .button {
                display: inline-flex;
                height: 50px;
                padding: 0;
                background: #009578;
                border: none;
                outline: none;
                border-radius: 5px;
                overflow: hidden;
                font-family: 'Quicksand', sans-serif;
                font-size: 16px;
                font-weight: 500;
                cursor: pointer;
            }
            .button:hover{
                background: #008168;   
            }
            .button:active{
                background: #006e58;   
            }
            .button__text,
            .button__icon{
                display: inline-flex;
                align-items: center;
                padding: 0 24px;
                color: #fff;
                height: 100%;
            }
            .button__icon{
                font-size: 1.5em; 
                background: rgba(0, 0, 0, 0.08);    
            }
          
            .centerDiv{
                margin: 0;
                padding: 0;
                text-align: center;
                position: absolute;
                top: 50%;
                left: 50%;
                transform: translateX(-50%);
            }
            .bottomDiv{
                margin: 0;
                padding: 0;
                text-align: center;
                position: absolute;
                top: 60%;
                left: 50%;
                transform: translateX(-50%);
            }
        </style>
    </head>
<body>
    
        <div class="centerDiv"> 
            <button type="button" class="button"onclick="fetch('/sentKeyPressToWebServer?button=Delay')">
                <span class="button__text">Delay</span>
                <span class="button__icon">
                    <ion-icon name="hourglass-sharp"></ion-icon>
                </span>
            </button>
)====");
String homePagePart2 = F(R"====(
<button type="button" class="button"onclick="fetch('/sentKeyPressToWebServer?button=Distortion')">
                <span class="button__text">Distortion</span>
                <span class="button__icon">
                    <ion-icon name="megaphone-sharp"></ion-icon>
                </span>
            </button>
)====");
String homePagePart3 = F(R"====(
<button type="button" class="button"onclick="fetch('/sentKeyPressToWebServer?button=Reverb')">
                    <span class="button__text">Reverb</span>
                    <span class="button__icon">
                        <ion-icon name="invert-mode-sharp"></ion-icon>
                </span>
            </button>
        </div>

            <div class="bottomDiv">
                <button type="button" class="button">
                    <span class="button__icon">
                        <ion-icon name="power-sharp"></ion-icon>
                </span>
            </button>
            </div>
    
    <script type="module" src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.esm.js"></script>
    <script nomodule src="https://unpkg.com/ionicons@5.5.2/dist/ionicons/ionicons.js"></script>
</body>
</html>
)====");
