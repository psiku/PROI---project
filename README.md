# Sheepskin Algorithm

# About

The Sheepskin Algorithm is a team project for object-oriented programming classes in second spring semester at WUT.

# Team

- Grzegorz Statkiewicz (team leader )
- Wiktor Kruszewicz
- Bartosz Psik

# Idea

The project involves the development of an algorithmic system for evaluating predictions used in  trading on the stock market. Such a project consists of several components:

1. Analysis and processing of stock market data - taking data from various sources, such as  reading and processing CSV or JSON files, and processing them to obtain the necessary information (also in the future we want to support stock market APIs).
2. Handling multiple instrument types - every has different properties used in strategy (f.e. variability)
3. Implementing various trading strategies - implementing various trading algorithms to analyse and predict future stock behaviours.
4. Evaluating final decision - using previous analyses return real-time final decision about each instrument based on input data.

# Plan

This section contains our milestones for this project. It’s split into most important features, listed under “Must have”, features nice to have and future features. 

## Must have

- Reading and parsing data from CSV file (containing f.e. date, instrument and price) to specific instrument class (f.e. crypto, stock or ETF)
- Handling at least three naive strategies (naive scenario evaluation algorithms)
- Evaluating short-term (current time) decision based on strategies results, and return it for each instrument (decision should be BUY, HOLD or SELL)
- Parsing and writing decision into CSV file (containing instrument and decision)

## Nice to have

- More accurate strategies (more complex algorithms)
- Validation of input file provided by user

## In the future

- Add stock API support to automate evaluation process
- Support for long-term predictions (feature moves in specified time interval)

# Milestones

We can next versions based on our plan:

### v0.1

- Reading provided file from user into specified structures
- Having one type of instrument
- Running one or two strategies and return result
- Not complex decision system based on above strategies results
- Writing decision to output file

### v0.2

- Implemented rest of instrument types
- Implemented rest of three algorithms
- Decision evaluation system based on all result from strategies

### v0.3

- Input file validation
- Precise current strategies with more complex analyses

# Domain

We can specify our domain with this subdomains.

### Data

Handles I/O operations.

### Strategy

Handles strategy running and calculating results based on provided data.

### Evaluation

Handles final result based on strategies calculations. Result decision could be:

- SELL
- HOLD
- BUY

# Documentation

![https://yuml.me/31d22f5d.jpg](https://yuml.me/31d22f5d.jpg)

## Classes

### CSVReader

Template class. Gets T type and provides methods to read content of CSV file onto provided type.

### CSVWriter

Template class. Gets T type and provides methods to write content to CSV file from provided type.

### Record

Class which holds common properties of current stock record in specified time unit. 

### Instrument

Parent class. Holds array of Record. Specifies child derived classes:

1. Stock
2. Cryptocurrency
3. ETF

which provides more complex specifiers for current type of instrument.

### Strategy

Parent abstract class. Specifies virtual methods, which are implemented in derived classes:

1. First strategy
2. Second strategy
3. Third strategy

which implements calculation algorithms and returns StrategyResult.

### DecisionEvaluation

Class for getting array of StrategyResult and providing method to calculate decision, which is enum with:

- SELL (-1)
- HOLD (0)
- BUY (1)
