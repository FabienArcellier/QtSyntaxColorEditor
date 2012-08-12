#ifndef CODEHIGHLIGHTER_H
#define CODEHIGHLIGHTER_H

#include "QSyntaxHighlighter"
#include "QList"

class QTextDocument;
class HighlightRule;

/*!
  * C++ Analyser class using in collaboration with QTextDocument to
  * manage syntax highligting
  */
class CodeHighlighter : public QSyntaxHighlighter
{
public:
    CodeHighlighter ( QTextDocument * parent );
    void highlightBlock(const QString &text);

private:
    QRegExp startComment;
    QRegExp endComment;

    QRegExp startPreprocessorInstruction;
    QRegExp nextLinePreprocessorInstruction;

};

#endif // CODEHIGHLIGHTER_H
