#include <Color.h>

hambourgeois::Color::Color(uchar red, uchar green, uchar blue) :
    Color(red, green, blue, 255)
{
}

hambourgeois::Color::Color(uchar red, uchar green, uchar blue, uchar alpha) :
    red(red), green(green), blue(blue), alpha(alpha)
{
}

void hambourgeois::Color::Set(const Color& c)
{
    red = c.red;
    green = c.green;
    blue = c.blue;
    alpha = c.alpha;
}

const hambourgeois::Color& hambourgeois::Color::MAROON = hambourgeois::Color(128, 0, 0);
const hambourgeois::Color& hambourgeois::Color::DARKRED = hambourgeois::Color(139, 0, 0);
const hambourgeois::Color& hambourgeois::Color::BROWN = hambourgeois::Color(165, 42, 42);
const hambourgeois::Color& hambourgeois::Color::FIREBRICK = hambourgeois::Color(178, 34, 34);
const hambourgeois::Color& hambourgeois::Color::CRIMSON = hambourgeois::Color(220, 20, 60);
const hambourgeois::Color& hambourgeois::Color::RED = hambourgeois::Color(255, 0, 0);
const hambourgeois::Color& hambourgeois::Color::TOMATO = hambourgeois::Color(255, 99, 71);
const hambourgeois::Color& hambourgeois::Color::CORAL = hambourgeois::Color(255, 127, 80);
const hambourgeois::Color& hambourgeois::Color::INDIANRED = hambourgeois::Color(205, 92, 92);
const hambourgeois::Color& hambourgeois::Color::LIGHTCORAL = hambourgeois::Color(240, 128, 128);
const hambourgeois::Color& hambourgeois::Color::DARKSALMON = hambourgeois::Color(233, 150, 122);
const hambourgeois::Color& hambourgeois::Color::SALMON = hambourgeois::Color(250, 128, 114);
const hambourgeois::Color& hambourgeois::Color::LIGHTSALMON = hambourgeois::Color(255, 160, 122);
const hambourgeois::Color& hambourgeois::Color::ORANGERED = hambourgeois::Color(255, 69, 0);
const hambourgeois::Color& hambourgeois::Color::DARKORANGE = hambourgeois::Color(255, 140, 0);
const hambourgeois::Color& hambourgeois::Color::ORANGE = hambourgeois::Color(255, 165, 0);
const hambourgeois::Color& hambourgeois::Color::GOLD = hambourgeois::Color(255, 215, 0);
const hambourgeois::Color& hambourgeois::Color::DARKGOLDENROD = hambourgeois::Color(184, 134, 11);
const hambourgeois::Color& hambourgeois::Color::GOLDENROD = hambourgeois::Color(218, 165, 32);
const hambourgeois::Color& hambourgeois::Color::PALEGOLDENROD = hambourgeois::Color(238, 232, 170);
const hambourgeois::Color& hambourgeois::Color::DARKKHAKI = hambourgeois::Color(189, 183, 107);
const hambourgeois::Color& hambourgeois::Color::KHAKI = hambourgeois::Color(240, 230, 140);
const hambourgeois::Color& hambourgeois::Color::OLIVE = hambourgeois::Color(128, 128, 0);
const hambourgeois::Color& hambourgeois::Color::YELLOW = hambourgeois::Color(255, 255, 0);
const hambourgeois::Color& hambourgeois::Color::YELLOWGREEN = hambourgeois::Color(154, 205, 50);
const hambourgeois::Color& hambourgeois::Color::DARKOLIVEGREEN = hambourgeois::Color(85, 107, 47);
const hambourgeois::Color& hambourgeois::Color::OLIVEDRAB = hambourgeois::Color(107, 142, 35);
const hambourgeois::Color& hambourgeois::Color::LAWNGREEN = hambourgeois::Color(124, 252, 0);
const hambourgeois::Color& hambourgeois::Color::CHARTREUSE = hambourgeois::Color(127, 255, 0);
const hambourgeois::Color& hambourgeois::Color::GREENYELLOW = hambourgeois::Color(173, 255, 47);
const hambourgeois::Color& hambourgeois::Color::DARKGREEN = hambourgeois::Color(0, 100, 0);
const hambourgeois::Color& hambourgeois::Color::GREEN = hambourgeois::Color(0, 128, 0);
const hambourgeois::Color& hambourgeois::Color::FORESTGREEN = hambourgeois::Color(34, 139, 34);
const hambourgeois::Color& hambourgeois::Color::LIME = hambourgeois::Color(0, 255, 0);
const hambourgeois::Color& hambourgeois::Color::LIMEGREEN = hambourgeois::Color(50, 205, 50);
const hambourgeois::Color& hambourgeois::Color::LIGHTGREEN = hambourgeois::Color(144, 238, 144);
const hambourgeois::Color& hambourgeois::Color::PALEGREEN = hambourgeois::Color(152, 251, 152);
const hambourgeois::Color& hambourgeois::Color::DARKSEAGREEN = hambourgeois::Color(143, 188, 143);
const hambourgeois::Color& hambourgeois::Color::MEDIUMSPRINGGREEN = hambourgeois::Color(0, 250, 154);
const hambourgeois::Color& hambourgeois::Color::SPRINGGREEN = hambourgeois::Color(0, 255, 127);
const hambourgeois::Color& hambourgeois::Color::SEAGREEN = hambourgeois::Color(46, 139, 87);
const hambourgeois::Color& hambourgeois::Color::MEDIUMAQUAMARINE = hambourgeois::Color(102, 205, 170);
const hambourgeois::Color& hambourgeois::Color::MEDIUMSEAGREEN = hambourgeois::Color(60, 179, 113);
const hambourgeois::Color& hambourgeois::Color::LIGHTSEAGREEN = hambourgeois::Color(32, 178, 170);
const hambourgeois::Color& hambourgeois::Color::DARKSLATEGRAY = hambourgeois::Color(47, 79, 79);
const hambourgeois::Color& hambourgeois::Color::TEAL = hambourgeois::Color(0, 128, 128);
const hambourgeois::Color& hambourgeois::Color::DARKCYAN = hambourgeois::Color(0, 139, 139);
const hambourgeois::Color& hambourgeois::Color::AQUA = hambourgeois::Color(0, 255, 255);
const hambourgeois::Color& hambourgeois::Color::CYAN = hambourgeois::Color(0, 255, 255);
const hambourgeois::Color& hambourgeois::Color::LIGHTCYAN = hambourgeois::Color(224, 255, 255);
const hambourgeois::Color& hambourgeois::Color::DARKTURQUOISE = hambourgeois::Color(0, 206, 209);
const hambourgeois::Color& hambourgeois::Color::TURQUOISE = hambourgeois::Color(64, 224, 208);
const hambourgeois::Color& hambourgeois::Color::MEDIUMTURQUOISE = hambourgeois::Color(72, 209, 204);
const hambourgeois::Color& hambourgeois::Color::PALETURQUOISE = hambourgeois::Color(175, 238, 238);
const hambourgeois::Color& hambourgeois::Color::AQUAMARINE = hambourgeois::Color(127, 255, 212);
const hambourgeois::Color& hambourgeois::Color::POWDERBLUE = hambourgeois::Color(176, 224, 230);
const hambourgeois::Color& hambourgeois::Color::CADETBLUE = hambourgeois::Color(95, 158, 160);
const hambourgeois::Color& hambourgeois::Color::STEELBLUE = hambourgeois::Color(70, 130, 180);
const hambourgeois::Color& hambourgeois::Color::CORNFLOWERBLUE = hambourgeois::Color(100, 149, 237);
const hambourgeois::Color& hambourgeois::Color::DEEPSKYBLUE = hambourgeois::Color(0, 191, 255);
const hambourgeois::Color& hambourgeois::Color::DODGERBLUE = hambourgeois::Color(30, 144, 255);
const hambourgeois::Color& hambourgeois::Color::LIGHTBLUE = hambourgeois::Color(173, 216, 230);
const hambourgeois::Color& hambourgeois::Color::SKYBLUE = hambourgeois::Color(135, 206, 235);
const hambourgeois::Color& hambourgeois::Color::LIGHTSKYBLUE = hambourgeois::Color(135, 206, 250);
const hambourgeois::Color& hambourgeois::Color::MIDNIGHTBLUE = hambourgeois::Color(25, 25, 112);
const hambourgeois::Color& hambourgeois::Color::NAVY = hambourgeois::Color(0, 0, 128);
const hambourgeois::Color& hambourgeois::Color::DARKBLUE = hambourgeois::Color(0, 0, 139);
const hambourgeois::Color& hambourgeois::Color::MEDIUMBLUE = hambourgeois::Color(0, 0, 205);
const hambourgeois::Color& hambourgeois::Color::BLUE = hambourgeois::Color(0, 0, 255);
const hambourgeois::Color& hambourgeois::Color::ROYALBLUE = hambourgeois::Color(65, 105, 225);
const hambourgeois::Color& hambourgeois::Color::BLUEVIOLET = hambourgeois::Color(138, 43, 226);
const hambourgeois::Color& hambourgeois::Color::INDIGO = hambourgeois::Color(75, 0, 130);
const hambourgeois::Color& hambourgeois::Color::DARKSLATEBLUE = hambourgeois::Color(72, 61, 139);
const hambourgeois::Color& hambourgeois::Color::SLATEBLUE = hambourgeois::Color(106, 90, 205);
const hambourgeois::Color& hambourgeois::Color::MEDIUMSLATEBLUE = hambourgeois::Color(123, 104, 238);
const hambourgeois::Color& hambourgeois::Color::MEDIUMPURPLE = hambourgeois::Color(147, 112, 219);
const hambourgeois::Color& hambourgeois::Color::DARKMAGENTA = hambourgeois::Color(139, 0, 139);
const hambourgeois::Color& hambourgeois::Color::DARKVIOLET = hambourgeois::Color(148, 0, 211);
const hambourgeois::Color& hambourgeois::Color::DARKORCHID = hambourgeois::Color(153, 50, 204);
const hambourgeois::Color& hambourgeois::Color::MEDIUMORCHID = hambourgeois::Color(186, 85, 211);
const hambourgeois::Color& hambourgeois::Color::PURPLE = hambourgeois::Color(128, 0, 128);
const hambourgeois::Color& hambourgeois::Color::THISTLE = hambourgeois::Color(216, 191, 216);
const hambourgeois::Color& hambourgeois::Color::PLUM = hambourgeois::Color(221, 160, 221);
const hambourgeois::Color& hambourgeois::Color::VIOLET = hambourgeois::Color(238, 130, 238);
const hambourgeois::Color& hambourgeois::Color::MAGENTA = hambourgeois::Color(255, 0, 255);
const hambourgeois::Color& hambourgeois::Color::ORCHID = hambourgeois::Color(218, 112, 214);
const hambourgeois::Color& hambourgeois::Color::MEDIUMVIOLETRED = hambourgeois::Color(199, 21, 133);
const hambourgeois::Color& hambourgeois::Color::PALEVIOLETRED = hambourgeois::Color(219, 112, 147);
const hambourgeois::Color& hambourgeois::Color::DEEPPINK = hambourgeois::Color(255, 20, 147);
const hambourgeois::Color& hambourgeois::Color::HOTPINK = hambourgeois::Color(255, 105, 180);
const hambourgeois::Color& hambourgeois::Color::LIGHTPINK = hambourgeois::Color(255, 182, 193);
const hambourgeois::Color& hambourgeois::Color::PINK = hambourgeois::Color(255, 192, 203);
const hambourgeois::Color& hambourgeois::Color::ANTIQUEWHITE = hambourgeois::Color(250, 235, 215);
const hambourgeois::Color& hambourgeois::Color::BEIGE = hambourgeois::Color(245, 245, 220);
const hambourgeois::Color& hambourgeois::Color::BISQUE = hambourgeois::Color(255, 228, 196);
const hambourgeois::Color& hambourgeois::Color::BLANCHEDALMOND = hambourgeois::Color(255, 235, 205);
const hambourgeois::Color& hambourgeois::Color::WHEAT = hambourgeois::Color(245, 222, 179);
const hambourgeois::Color& hambourgeois::Color::CORNSILK = hambourgeois::Color(255, 248, 220);
const hambourgeois::Color& hambourgeois::Color::LEMONCHIFFON = hambourgeois::Color(255, 250, 205);
const hambourgeois::Color& hambourgeois::Color::LIGHTGOLDENRODYELLOW = hambourgeois::Color(250, 250, 210);
const hambourgeois::Color& hambourgeois::Color::LIGHTYELLOW = hambourgeois::Color(255, 255, 224);
const hambourgeois::Color& hambourgeois::Color::SADDLEBROWN = hambourgeois::Color(139, 69, 19);
const hambourgeois::Color& hambourgeois::Color::SIENNA = hambourgeois::Color(160, 82, 45);
const hambourgeois::Color& hambourgeois::Color::CHOCOLATE = hambourgeois::Color(210, 105, 30);
const hambourgeois::Color& hambourgeois::Color::PERU = hambourgeois::Color(205, 133, 63);
const hambourgeois::Color& hambourgeois::Color::SANDYBROWN = hambourgeois::Color(244, 164, 96);
const hambourgeois::Color& hambourgeois::Color::BURLYWOOD = hambourgeois::Color(222, 184, 135);
const hambourgeois::Color& hambourgeois::Color::TAN = hambourgeois::Color(210, 180, 140);
const hambourgeois::Color& hambourgeois::Color::ROSYBROWN = hambourgeois::Color(188, 143, 143);
const hambourgeois::Color& hambourgeois::Color::MOCCASIN = hambourgeois::Color(255, 228, 181);
const hambourgeois::Color& hambourgeois::Color::NAVAJOWHITE = hambourgeois::Color(255, 222, 173);
const hambourgeois::Color& hambourgeois::Color::PEACHPUFF = hambourgeois::Color(255, 218, 185);
const hambourgeois::Color& hambourgeois::Color::MISTYROSE = hambourgeois::Color(255, 228, 225);
const hambourgeois::Color& hambourgeois::Color::LAVENDERBLUSH = hambourgeois::Color(255, 240, 245);
const hambourgeois::Color& hambourgeois::Color::LINEN = hambourgeois::Color(250, 240, 230);
const hambourgeois::Color& hambourgeois::Color::OLDLACE = hambourgeois::Color(253, 245, 230);
const hambourgeois::Color& hambourgeois::Color::PAPAYAWHIP = hambourgeois::Color(255, 239, 213);
const hambourgeois::Color& hambourgeois::Color::SEASHELL = hambourgeois::Color(255, 245, 238);
const hambourgeois::Color& hambourgeois::Color::MINTCREAM = hambourgeois::Color(245, 255, 250);
const hambourgeois::Color& hambourgeois::Color::SLATEGRAY = hambourgeois::Color(112, 128, 144);
const hambourgeois::Color& hambourgeois::Color::LIGHTSLATEGRAY = hambourgeois::Color(119, 136, 153);
const hambourgeois::Color& hambourgeois::Color::LIGHTSTEELBLUE = hambourgeois::Color(176, 196, 222);
const hambourgeois::Color& hambourgeois::Color::LAVENDER = hambourgeois::Color(230, 230, 250);
const hambourgeois::Color& hambourgeois::Color::FLORALWHITE = hambourgeois::Color(255, 250, 240);
const hambourgeois::Color& hambourgeois::Color::ALICEBLUE = hambourgeois::Color(240, 248, 255);
const hambourgeois::Color& hambourgeois::Color::GHOSTWHITE = hambourgeois::Color(248, 248, 255);
const hambourgeois::Color& hambourgeois::Color::HONEYDEW = hambourgeois::Color(240, 255, 240);
const hambourgeois::Color& hambourgeois::Color::IVORY = hambourgeois::Color(255, 255, 240);
const hambourgeois::Color& hambourgeois::Color::AZURE = hambourgeois::Color(240, 255, 255);
const hambourgeois::Color& hambourgeois::Color::SNOW = hambourgeois::Color(255, 250, 250);
const hambourgeois::Color& hambourgeois::Color::BLACK = hambourgeois::Color(0, 0, 0);
const hambourgeois::Color& hambourgeois::Color::DIMGREY = hambourgeois::Color(105, 105, 105);
const hambourgeois::Color& hambourgeois::Color::GREY = hambourgeois::Color(128, 128, 128);
const hambourgeois::Color& hambourgeois::Color::DARKGREY = hambourgeois::Color(169, 169, 169);
const hambourgeois::Color& hambourgeois::Color::SILVER = hambourgeois::Color(192, 192, 192);
const hambourgeois::Color& hambourgeois::Color::LIGHTGREY = hambourgeois::Color(211, 211, 211);
const hambourgeois::Color& hambourgeois::Color::GAINSBORO = hambourgeois::Color(220, 220, 220);
const hambourgeois::Color& hambourgeois::Color::WHITESMOKE = hambourgeois::Color(245, 245, 245);
const hambourgeois::Color& hambourgeois::Color::WHITE = hambourgeois::Color(255, 255, 255);