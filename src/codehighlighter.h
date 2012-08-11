#ifndef CODEHIGHLIGHTER_H
#define CODEHIGHLIGHTER_H

#include "QSyntaxHighlighter"
#include "QTextDocument"

class CodeHighlighter : public QSyntaxHighlighter
{
public:
    CodeHighlighter ( QTextDocument * parent );
    void highlightBlock(const QString &text);
};

#endif // CODEHIGHLIGHTER_H
