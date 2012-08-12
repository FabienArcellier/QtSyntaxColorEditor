#include "codehighlighter.h"
#include <QDebug>

CodeHighlighter::CodeHighlighter ( QTextDocument * parent ) :
    QSyntaxHighlighter(parent)
{

}

void CodeHighlighter::highlightBlock(const QString &text)
{
    qDebug() << text;

    //Reset the line at a neutral state
    this->setCurrentBlockState(0);

    QRegExp start("/\\*");
    QRegExp end("\\*/");
    int start_index = -1;
    bool is_comment_block = false;
    QTextFormat multiLineCommentFormat;
    multiLineCommentFormat.setForeground(Qt::darkGreen);

    /*
      * You can write this block of instructions using only
      * start_index. Look at Syntax Highlighter exemple
      */
    if (this ->previousBlockState() == 1)
    {
        start_index = 0;
        is_comment_block = true;
    }
    else
    {
        start_index = start.indexIn(text);
        is_comment_block = start_index != -1;
    }

    if (is_comment_block)
    {
        int end_index = end.indexIn(text);
        if (end_index == -1)
        {
            // There we change the state of the line in text editor
            // If the state has been changed the method highlightBlock will be call on the
            // next line
            this->setCurrentBlockState(1);
        }
    }
}
