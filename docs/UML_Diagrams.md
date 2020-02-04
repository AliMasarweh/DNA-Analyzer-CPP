# **Class Diagram**
```plantuml
@startuml
left to right direction
package DNAnalyzer{
package controller{
interface CLICommand{
    {abstract} execute(): string
}

class CLICommandFactory{
    createCommand(string op)
}

class Batch{
    vector<Batch*>
}

class CLINewCommand{
    execute(): string
}

class CLISliceCommand{
    execute(): string
}

class CLIPairCommand{
    execute(): string
}


class CLISaveCommand{
    execute(): string
}

class CLIDefualtLabelCommand{
    execute(): string
}

class CLIMaxCommand{
    execute(): string
}

package DNALabeling{
    class ResultLabeling{
        + map<label, id>
    }
    class LabelActions{
        + calc(value, label)
        + calc(label, value)
        + calc(label, label)
        + max(label..., value...)
        + min(label..., value...)
    }
    class LastRefences{
        + lastCalculationId
        + lastCalculationValue
    }
}


class Controller{
    {static} + executeCommand(ReferencedOperation&): string
}

class  IndexDNASequence{
    - size_t id
    - string name
}
}


package Model{
class DNASequence{
    - Nuclotide seq[]
    - size_t len

    + operator[](size_t)
    + getLength()

    {static} + readFromFile()
    {static} + writeToFile()

    + slice(begin, end=len)
    + pair()
    + find(DNASequence)
    + count(DNASequence)
    + findAll(DNASequence) => vector<begin>
    + findConsensus(DNASequence) => vector<interval>

}

class  Nuclotide{
    - char nuc;
    + Nuclotide(char)
    {static} + isValidNuclotide()
}

class Codon{
    {static} - startingCodon
    {static} - endingCodon
    {static} + isStartingCodon()
    {static} + isEndingCodon()
}

class Streamer{
    + Streamer(
        compressor=toBits)
    + writeToFile(path)
    + readFromFile(path)
}
}

package View{
class CLI{
    - map<id, sequence>
    - map<name, id>
    - map<id, batches>

    + getDNAById()
    + getDNAByName()
}

class ReferencedOperation{
    - string op
    - vector<ReferencedOperation*> args
    - string arg
    - string refrence
}

class Parser{
    
    parse(string): ReferencedOperation
}
}

}
DNASequence o-- Nuclotide
DNASequence --> Codon
DNASequence --> Streamer
IndexDNASequence --|> DNASequence

IndexDNASequence <-- CLINewCommand
IndexDNASequence <-- CLISliceCommand
IndexDNASequence <-- CLIPairCommand

CLI --> Parser
Parser --> Controller
Parser  o-- ReferencedOperation
Controller o-- Batch

CLICommandFactory --> CLICommand
Controller --> CLICommandFactory


CLICommand <|-- CLINewCommand

CLICommand <|-- CLISliceCommand
CLICommand <|-- CLIPairCommand
CLICommand <|-- CLISaveCommand

CLICommand <|-- CLIDefualtLabelCommand
CLICommand <|-- CLIMaxCommand

CLIDefualtLabelCommand --> LastRefences
CLIMaxCommand --> LabelActions
@enduml
```
# **Use-Case Diagram**

```plantuml
@startuml
left to right direction
skinparam packageStyle rectangle
actor biologist
rectangle CLI{
    (read)
    (write)
}
rectangle checkout {
  biologist --> (manipulation)
  biologist --> (analysis)
  biologist --> (createDNA)
  biologist --> (manageDataBase)
  biologist --> (control)
  (createDNA) .> (manipulation) : extends
  (createDNA) .> (analysis) : extends
  (manipulation) .> (labeling) : includes
  (analysis) .> (labeling) : includes

  (manipulation) -- CLI
  (analysis) -- CLI
  (labeling) -- CLI
}
@enduml
```
# **Deployment Diagram**
```plantuml

@startuml
artifact analyzer
package Controller
package DNASequence

analyzer --> Controller
Controller --> DNASequence
DNASequence --> Controller
Controller --> analyzer
@enduml

```