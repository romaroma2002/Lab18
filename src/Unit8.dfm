object Form8: TForm8
  Left = 753
  Top = 137
  Width = 300
  Height = 250
  Caption = #1057#1086#1088#1090#1091#1074#1072#1085#1085#1103
  Color = clBtnFace
  Constraints.MaxHeight = 250
  Constraints.MaxWidth = 300
  Constraints.MinHeight = 250
  Constraints.MinWidth = 300
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 120
    Top = 24
    Width = 26
    Height = 13
    Caption = #1055#1086#1083#1077
  end
  object Label2: TLabel
    Left = 104
    Top = 96
    Width = 59
    Height = 13
    Caption = #1057#1086#1088#1090#1091#1074#1072#1085#1085#1103
  end
  object ComboBox1: TComboBox
    Left = 72
    Top = 40
    Width = 129
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 0
    OnChange = ComboBox1Change
  end
  object ComboBox2: TComboBox
    Left = 72
    Top = 112
    Width = 129
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 1
  end
  object Button1: TButton
    Left = 80
    Top = 152
    Width = 121
    Height = 25
    Caption = #1057#1086#1088#1090#1091#1074#1072#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
end
