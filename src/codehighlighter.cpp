#include "codehighlighter.h"
#include <QDebug>

CodeHighlighter::CodeHighlighter ( QTextDocument * parent ) :
    QSyntaxHighlighter(parent)
{

}

void CodeHighlighter::highlightBlock(const QString &text)
{
    qDebug() << text;
    QTextCharFormat multiLineCommentFormat;
     multiLineCommentFormat.setForeground(Qt::red);

     QRegExp startExpression("/\\*");
     QRegExp endExpression("\\*/");

     setCurrentBlockState(0);

     int startIndex = 0;
     if (previousBlockState() != 1)
         startIndex = text.indexOf(startExpression);

     while (startIndex >= 0) {
        int endIndex = text.indexOf(endExpression, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + endExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(startExpression,
                                  startIndex + commentLength);
     }
 }
