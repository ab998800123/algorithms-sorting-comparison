object Form4: TForm4
  Left = 0
  Top = 0
  Caption = 'Form4'
  ClientHeight = 650
  ClientWidth = 781
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object PageControl1: TPageControl
    Left = 216
    Top = 0
    Width = 565
    Height = 650
    ActivePage = TabSheet1
    Align = alRight
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = 'TabSheet1'
      object Label3: TLabel
        Left = 296
        Top = 130
        Width = 26
        Height = 15
        Caption = #26178#38291
      end
      object Memo1: TMemo
        Left = 0
        Top = 151
        Width = 241
        Height = 466
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssVertical
        TabOrder = 0
      end
      object Memo2: TMemo
        Left = 296
        Top = 151
        Width = 249
        Height = 466
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssVertical
        TabOrder = 1
      end
      object CheckBox10: TCheckBox
        Left = 3
        Top = 128
        Width = 97
        Height = 17
        Caption = #25490#24207#32080#26524
        TabOrder = 2
      end
      object CheckBox11: TCheckBox
        Left = 106
        Top = 128
        Width = 97
        Height = 17
        Caption = #26597#30475#21407#24335
        TabOrder = 3
      end
    end
    object TabSheet2: TTabSheet
      Caption = #22294#34920
      ImageIndex = 1
      object Chart1: TChart
        Left = 0
        Top = 0
        Width = 557
        Height = 620
        Title.Text.Strings = (
          'TChart')
        Align = alClient
        TabOrder = 0
        ExplicitLeft = 88
        ExplicitTop = 198
        ExplicitWidth = 400
        ExplicitHeight = 250
        DefaultCanvas = 'TGDIPlusCanvas'
        PrintMargins = (
          15
          19
          15
          19)
        ColorPaletteIndex = 13
        object Series1: TFastLineSeries
          HoverElement = []
          LinePen.Color = 10708548
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
    end
  end
  object GroupBox1: TGroupBox
    Left = -4
    Top = 8
    Width = 218
    Height = 194
    Caption = 'input'
    TabOrder = 1
    object Label1: TLabel
      Left = 31
      Top = 54
      Width = 23
      Height = 21
      Caption = 'N='
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 3
      Top = 81
      Width = 51
      Height = 21
      Caption = 'range='
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 6
      Top = 113
      Width = 49
      Height = 21
      Caption = 'times='
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
    end
    object Edit3: TEdit
      Left = 61
      Top = 115
      Width = 121
      Height = 23
      TabOrder = 0
      Text = '1'
    end
    object Edit2: TEdit
      Left = 60
      Top = 81
      Width = 121
      Height = 23
      TabOrder = 1
      Text = '5'
    end
    object Edit1: TEdit
      Left = 60
      Top = 52
      Width = 121
      Height = 23
      TabOrder = 2
      Text = '3'
    end
  end
  object GroupBox2: TGroupBox
    Left = -3
    Top = 200
    Width = 217
    Height = 249
    Caption = 'sort'
    TabOrder = 2
    object CheckBox1: TCheckBox
      Left = 3
      Top = 26
      Width = 97
      Height = 17
      Caption = 'Selection sort '
      TabOrder = 0
    end
    object CheckBox2: TCheckBox
      Left = 3
      Top = 49
      Width = 97
      Height = 17
      Caption = 'Insertion sort   '
      TabOrder = 1
    end
    object CheckBox3: TCheckBox
      Left = 3
      Top = 72
      Width = 97
      Height = 17
      Caption = 'Bubble sort'
      TabOrder = 2
    end
    object CheckBox4: TCheckBox
      Left = 3
      Top = 95
      Width = 194
      Height = 17
      Caption = 'Quick sort (recursive versions)'
      TabOrder = 3
    end
    object CheckBox5: TCheckBox
      Left = 3
      Top = 118
      Width = 214
      Height = 17
      Caption = 'Quick sort (non-recursive versions)'
      TabOrder = 4
    end
    object CheckBox6: TCheckBox
      Left = 3
      Top = 141
      Width = 210
      Height = 17
      Caption = ' Merge sort (recursive versions)'
      TabOrder = 5
    end
    object CheckBox7: TCheckBox
      Left = 3
      Top = 164
      Width = 214
      Height = 17
      Caption = 'Merge sort (non-recursive versions)'
      TabOrder = 6
    end
    object CheckBox8: TCheckBox
      Left = 3
      Top = 187
      Width = 97
      Height = 17
      Caption = 'Heap sort'
      TabOrder = 7
    end
    object CheckBox9: TCheckBox
      Left = 3
      Top = 210
      Width = 97
      Height = 17
      Caption = 'Radix sort'
      TabOrder = 8
    end
    object Button1: TButton
      Left = 142
      Top = 221
      Width = 75
      Height = 25
      Caption = 'run'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Segoe UI'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      OnClick = Button1Click
    end
  end
  object Button2: TButton
    Left = 41
    Top = 536
    Width = 120
    Height = 41
    Caption = #24314#31435#22294#34920
    TabOrder = 3
    OnClick = Button2Click
  end
end
