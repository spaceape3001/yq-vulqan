////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ft2build.h>
#include <freetype/freetype.h>

#include <format>
#include <iostream>
#include <set>

FT_Library  gLibrary;

std::pair<uint32_t, uint32_t>   rowcol(char32_t ch)
{
    return { ((uint32_t) ch) >> 4, ((uint32_t) ch) & 0xF };
}

void    load_and_print(const char* file)
{
    FT_Face face;
    if(int err = FT_New_Face(gLibrary, file, 0, &face)){
        std::cerr << "Unable to load file: " << file << " (" << err << ")\n";
        return ;
    }
    
    std::cout << "File> " << file << '\n'
        << "  Family: " << face->family_name << '\n'
        << "  Style: " << face->style_name << '\n'
        << "  Number of faces: " << face->num_faces << '\n'
        << "  Face Index: " << face->face_index << '\n'
        << "  Number Glyphs: " << face->num_glyphs << '\n'
    ;
    
    std::set<char32_t>  found;
    for(int n=0;n<face->num_charmaps;++n){
        FT_CharMap  cm = face->charmaps[n];
        FT_Set_Charmap( face, cm );
        
        FT_UInt     gindex = 0;
        
        for(FT_ULong charcode = FT_Get_First_Char(face, &gindex); gindex; charcode = FT_Get_Next_Char(face, charcode, &gindex)){
            found.insert((char32_t) charcode);
        }
    }
    
    std::cout << "  Table:";
    char32_t    last    = 0x0;
    static const char   bytes[] = "0123456789ABCDEF?";
    char buffer[32];
    bool        first   = true;

    for(char32_t ch : found){
        auto [r,c]      = rowcol(ch);
        auto [lr,lc]    = rowcol(last);
        
        if((r!=lr) || first){
            first   = false;
            std::cout << "\n";
            sprintf(buffer, "%7Xx ", (int) r);
            std::cout << buffer;
        }
        if(r != lr){
            for(int x=0;x<(int) c;++x)
                std::cout << "  ";
        } else {
            for(int x=lc+1;x<(int) c;++x)
                std::cout << "  ";
        }
        std::cout << " " << bytes[c];
        last = ch;
    }
    std::cout << '\n';
}

int main(int argc, char* argv[])
{
    if(argc<=1){
        std::cout << "Usage: fontchars <somefont.ttf>\n";
        return 0;
    }
    
    if(int err = FT_Init_FreeType(&gLibrary)){
        std::cerr << "Unable to initialize the free type library (" << err << ")\n";
        return -1;
    }
    
    for(int i=1;i<argc;++i)
        load_and_print(argv[i]);
    return 0;
}
