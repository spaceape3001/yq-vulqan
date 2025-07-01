////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

/*
    Simple "demo" utilitiy
*/

#include <yq/core/Logging.hpp>
#include <yq/file/FileUtils.hpp>
#include <yq/meta/Meta.hpp>
#include <yq/meta/ObjectMetaWriter.hpp>
#include <yq/process/PluginLoader.hpp>
#include <yq/text/format.hpp>

#include <tachyon/application.hpp>
#include <tachyon/MyImGui.hpp>
#include <tachyon/viewer.hpp>
#include <tachyon/widget.hpp>
#include <tachyon/widget/TextArea.hpp>
#include <tachyon/api/Tachyon.hxx>

#include <iostream>
#include <TextEditor.h>
#include <ImGuiFileDialog.h>
//

using namespace yq;
using namespace yq::tachyon;

const char* szSpeech = 
"No man thinks more highly than I do of the patriotism, as well as abilities, of the very worthy gentlemen who have\n\
just addressed the House. But different men often see the same subject in different lights; and, therefore, I hope it\n\
will not be thought disrespectful to those gentlemen if, entertaining as I do opinions of a character very opposite to\n\
theirs, I shall speak forth my sentiments freely and without reserve. This is no time for ceremony. The questing before\n\
the House is one of awful moment to this country. For my own part, I consider it as nothing less than a question of\n\
freedom or slavery; and in proportion to the magnitude of the subject ought to be the freedom of the debate. It is only\n\
in this way that we can hope to arrive at truth, and fulfill the great responsibility which we hold to God and our\n\
country. Should I keep back my opinions at such a time, through fear of giving offense, I should consider myself as\n\
guilty of treason towards my country, and of an act of disloyalty toward the Majesty of Heaven, which I revere above\n\
all earthly kings.\n\
\n\
Mr. President, it is natural to man to indulge in the illusions of hope. We are apt to shut our eyes against a painful\n\
truth, and listen to the song of that siren till she transforms us into beasts. Is this the part of wise men, engaged\n\
in a great and arduous struggle for liberty? Are we disposed to be of the number of those who, having eyes, see not,\n\
and, having ears, hear not, the things which so nearly concern their temporal salvation? For my part, whatever anguish\n\
of spirit it may cost, I am willing to know the whole truth; to know the worst, and to provide for it. I have but one\n\
lamp by which my feet are guided, and that is the lamp of experience. I know of no way of judging the future but by the\n\
past. And judging by the past, I wish to know what there has been in the conduct of the British ministry for the last\n\
ten years to justify those hopes with which gentlemen have been pleased to solace themselves and the House. Is it that\n\
insidious smile with which our petition has been lately received? Trust it not, sir; it will prove a snare to your\n\
feet.  Suffer not yourselves to be betrayed with a kiss. Ask yourselves how this gracious reception of our petition\n\
comports with those warlike preparations which cover our waters and darken our land. Are fleets and armies necessary\n\
to a work of love and reconciliation? Have we shown ourselves so unwilling to be reconciled that force must be called\n\
in to win back our love? Let us not deceive ourselves, sir. These are the implements of war and subjugation; the last\n\
arguments to which kings resort. I ask gentlemen, sir, what means this martial array, if its purpose be not to force us\n\
to submission? Can gentlemen assign any other possible motive for it? Has Great Britain any enemy, in this quarter of\n\
the world, to call for all this accumulation of navies and armies? No, sir, she has none. They are meant for us: they\n\
can be meant for no other. They are sent over to bind and rivet upon us those chains which the British ministry have\n\
been so long forging. And what have we to oppose to them? Shall we try argument? Sir, we have been trying that for the\n\
last ten years. Have we anything new to offer upon the subject? Nothing. We have held the subject up in every light of\n\
which it is capable; but it has been all in vain. Shall we resort to entreaty and humble supplication? What terms shall\n\
we find which have not been already exhausted? Let us not, I beseech you, sir, deceive ourselves. Sir, we have done\n\
everything that could be done to avert the storm which is now coming on. We have petitioned; we have remonstrated; we\n\
have supplicated; we have prostrated ourselves before the throne, and have implored its interposition to arrest the\n\
tyrannical hands of the ministry and Parliament. Our petitions have been slighted; our remonstrances have produced\n\
additional violence and insult; our supplications have been disregarded; and we have been spurned, with contempt, from\n\
the foot of the throne! In vain, after these things, may we indulge the fond hope of peace and reconciliation. There is\n\
no longer any room for hope. If we wish to be free– if we mean to preserve inviolate those inestimable privileges for\n\
which we have been so long contending–if we mean not basely to abandon the noble struggle in which we have been so long\n\
engaged, and which we have pledged ourselves never to abandon until the glorious object of our contest shall be\n\
obtained–we must fight! I repeat it, sir, we must fight! An appeal to arms and to the God of hosts is all that is left us!\n\
\n\
They tell us, sir, that we are weak; unable to cope with so formidable an adversary. But when shall we be stronger?\n\
Will it be the next week, or the next year? Will it be when we are totally disarmed, and when a British guard shall be\n\
stationed in every house? Shall we gather strength by irresolution and inaction? Shall we acquire the means of\n\
effectual resistance by lying supinely on our backs and hugging the delusive phantom of hope, until our enemies shall\n\
have bound us hand and foot? Sir, we are not weak if we make a proper use of those means which the God of nature hath\n\
placed in our power. The millions of people, armed in the holy cause of liberty, and in such a country as that which we\n\
possess, are invincible by any force which our enemy can send against us. Besides, sir, we shall not fight our battles\n\
alone. There is a just God who presides over the destinies of nations, and who will raise up friends to fight our\n\
battles for us. The battle, sir, is not to the strong alone; it is to the vigilant, the active, the brave. Besides,\n\
sir, we have no election. If we were base enough to desire it, it is now too late to retire from the contest. There is\n\
no retreat but in submission and slavery! Our chains are forged! Their clanking may be heard on the plains of Boston!\n\
The war is inevitable–and let it come! I repeat it, sir, let it come.\n\
\n\
It is in vain, sir, to extenuate the matter. Gentlemen may cry, Peace, Peace– but there is no peace. The war is actually\n\
begun! The next gale that sweeps from the north will bring to our ears the clash of resounding arms! Our brethren are\n\
already in the field! Why stand we here idle? What is it that gentlemen wish? What would they have? Is life so dear, or\n\
peace so sweet, as to be purchased at the price of chains and slavery? Forbid it, Almighty God! I know not what course\n\
others may take; but as for me, give me liberty or give me death!";

class GTEditor : public Widget, public TextEditor {
    YQ_OBJECT_DECLARE(GTEditor, Widget)
public:
    GTEditor(const std::filesystem::path& fpath=std::filesystem::path())
    {
        if(!fpath.empty()){
            SetText(file_string(fpath));
            m_path  = fpath;
        }
        
        static uint64_t     s_id  = 1;
        
        m_textid        = std::string("TextKing:") + to_string(s_id++);
        
    }
    
    void    imgui(ViContext&) override;
    
private:
    std::filesystem::path   m_path;
    std::string             m_textid;
};

class N2Editor : public Widget {
    YQ_OBJECT_DECLARE(N2Editor, Widget)
public:

    N2Editor([[maybe_unused]] const std::filesystem::path& fpath=std::filesystem::path())
    {
        m_edit  = new widget::TextArea;
        m_edit -> set_text(szSpeech);
yInfo() << "Line count is " << m_edit -> line_count();        
    }
    
    void    imgui(ViContext&) override;
    
    widget::TextArea*       m_edit = nullptr;
};

void GTEditor::imgui(ViContext&)
{
    using namespace ImGui;
    auto cpos   = GetCursorPosition();
    Begin(m_textid.c_str(), nullptr, ImGuiWindowFlags_HorizontalScrollbar);
    SetWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
    Text("%6d/%-6d %6d lines  | %s | %s | %s | %s", cpos.mLine + 1, cpos.mColumn + 1, GetTotalLines(),
			IsOverwrite() ? "Ovr" : "Ins",
			CanUndo() ? "*" : " ",
			GetLanguageDefinition().mName.c_str(), m_path.c_str());
    TextEditor::Render("TextEditor");
    End();
}

void    N2Editor::imgui(ViContext&u) 
{
    using namespace ImGui;
    //auto cpos   = GetCursorPosition();
    PushID((int) id());
    PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 0.0f));
    PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    Begin("N2Editor", nullptr, ImGuiWindowFlags_HorizontalScrollbar);
    SetWindowSize(ImVec2(800, 600), ImGuiCond_FirstUseEver);
    //Text("%6d/%-6d %6d lines  | %s | %s | %s | %s", cpos.mLine + 1, cpos.mColumn + 1, GetTotalLines(),
			//IsOverwrite() ? "Ovr" : "Ins",
			//CanUndo() ? "*" : " ",
			//GetLanguageDefinition().mName.c_str(), m_path.c_str());
    m_edit -> imgui(u);
    End();
    PopStyleVar();
    PopStyleVar();
    PopID();
}

class TextKing : public Widget {
    YQ_OBJECT_DECLARE(TextKing, Widget)
public:
    static void init_meta()
    {
        auto w = writer<TextKing>();
        w.imgui();
    }

    TextKing() 
    {
    }
    
    ~TextKing()
    {
        for(auto w : m_editors)
            delete w;
        m_editors.clear();
    }
    
    void   imgui(ViContext&u) override 
    {
        enum FileMode   {
            NONE    = 0,
            OPEN,
            SAVE
        };
        
        static auto*    file_dialog = IGFD::FileDialog::Instance();
        
        FileMode        file_mode   = NONE;
        const char*     file_title  = nullptr;
        
        using namespace ImGui;
        if(BeginMainMenuBar()){
            if(BeginMenu("File")){
                if(MenuItem("New")){
                    install(new GTEditor);
                }
                if(MenuItem("NewB")){
                    install(new N2Editor);
                }
                if(MenuItem("Open")){
                    //file_mode       = OPEN;
                    //file_title      = "Open Text File";
                    //file_dialog.Open(file_title, "Open a file");
                }
                if(MenuItem("Save")){
                
                }
                if(MenuItem("Save As")){
                
                }
                Separator();
                if(MenuItem("Quit")){
                    
                }
                EndMenu();
            }
            if(BeginMenu("Edit")){
                if(MenuItem("Undo")){
                } 
                if(MenuItem("Redo")){
                }
                Separator();
                if(MenuItem("Cut")){
                }
                if(MenuItem("Copy")){
                }
                if(MenuItem("Paste")){
                }
                if(MenuItem("Clear")){
                }
                Separator();
                if(MenuItem("Select All")){
                }
                EndMenu();
            }
            ImGui::EndMainMenuBar();
        }
        
        for(auto& e : m_editors)
            e->imgui(u);
            
        switch(file_mode){
        case OPEN:
            //if(file_dialog.IsDone(file_title)){
                //if(file_dialog.HasResult()){
                    //std::string res = file_dialog.GetResult().u8string();
                    //if(!res.empty()){
                        //install(new Editor(res));
                    //}
                //}
            //}
            break;
        case SAVE:
            break;
        default:
            break;
        }
    }
    
    void    install(GTEditor* editor)
    {
        m_editors.push_back(editor);
        m_active                = editor;
    }

    void    install(N2Editor* editor)
    {
        m_editors.push_back(editor);
    }
    
    std::vector<Widget*>    m_editors;
    GTEditor*               m_active = nullptr;
};

YQ_OBJECT_IMPLEMENT(TextKing)
YQ_OBJECT_IMPLEMENT(GTEditor)
YQ_OBJECT_IMPLEMENT(N2Editor)

int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    aci.app_name            = "textking";
    aci.view.title          = "TextKING!";
    aci.view.clear          = { 0.0, 0.2, 0.5, 1. };
    aci.view.resizable      = true;
    aci.view.imgui          = true;
    //aci.view.pmode        = VK_PRESENT_MODE_IMMEDIATE_KHR;  // <-< Set this if you want to see how fast your CPU & GPU can go!  (Metrics under Tools menu.)

    Application app(argc, argv, aci);
    load_plugin_dir("plugin");
    app.finalize();
    app.run(Widget::create<TextKing>());
    return 0;
}
